use std::fs::{self, File};
use std::io::{BufWriter, Write};

const EPSILON: f64 = 1.0;
const DELTA: f64 = 0.1;
const NX: usize = 150;
const NY: usize = 100;
const V_1: f64 = 10.0;
const X_MAX: f64 = DELTA * NX as f64;
const Y_MAX: f64 = DELTA * NY as f64;
const SIGMA_X: f64 = 0.1 * X_MAX;
const SIGMA_Y: f64 = 0.1 * Y_MAX;
const TOL: f64 = 1e-8;

fn main() {
    fs::create_dir_all("plots").expect("Unable to create folder!");

    let mut ro: [[f64; NY + 1]; NX + 1] = [[0.0; NY + 1]; NX + 1];
    for i in 0..=NX {
        for j in 0..=NY {
            ro[i][j] = calc_ro(i as f64 * DELTA, j as f64 * DELTA);
        }
    }

    // RELAKSACJA GLOBALNA

    let omega_gs = [0.6, 1.0];

    for omega_g in omega_gs {
        let mut vs: [[f64; NY + 1]; NX + 1] = [[0.0; NY + 1]; NX + 1];
        let mut vn: [[f64; NY + 1]; NX + 1] = [[0.0; NY + 1]; NX + 1];
        for i in 0..=NX {
            vs[i][0] = V_1;
            vn[i][0] = V_1;
        }
        let mut err: [[f64; NY]; NX] = [[0.0; NY]; NX];
        let mut s_prev;
        let mut s_next = 0.0;
        let mut it = 0;

        let f_gs =
            File::create(format!("plots/gs_{}.txt", omega_g)).expect("Unable to create file!");
        let mut f_gs = BufWriter::new(f_gs);
        let f_vn =
            File::create(format!("plots/vn_{}.txt", omega_g)).expect("Unable to create file!");
        let mut f_vn = BufWriter::new(f_vn);
        let f_err =
            File::create(format!("plots/err_{}.txt", omega_g)).expect("Unable to create file!");
        let mut f_err = BufWriter::new(f_err);

        println!(
            "Calculating with global relaxation for omega_g = {}",
            omega_g
        );
        loop {
            it += 1;
            //relaksacja globalna
            for i in 1..NX {
                for j in 1..NY {
                    vn[i][j] = 0.25
                        * (vs[i + 1][j]
                            + vs[i - 1][j]
                            + vs[i][j + 1]
                            + vs[i][j - 1]
                            + DELTA * DELTA * ro[i][j] / EPSILON);
                }
            }
            // krok 2
            for j in 1..NY {
                vn[0][j] = vn[1][j];
                vn[NX][j] = vn[NX - 1][j];
            }
            // krok 3 mieszanie
            for i in 0..=NX {
                for j in 0..=NY {
                    vs[i][j] = (1.0 - omega_g) * vs[i][j] + omega_g * vn[i][j];
                }
            }
            // błąd
            s_prev = s_next;
            s_next = 0.0;
            for i in 0..NX {
                for j in 0..NY {
                    s_next += DELTA
                        * DELTA
                        * (0.5 * (vs[i + 1][j] - vs[i][j]) / DELTA * (vs[i + 1][j] - vs[i][j])
                            / DELTA
                            + 0.5 * (vs[i][j + 1] - vs[i][j]) / DELTA * (vs[i][j + 1] - vs[i][j])
                                / DELTA
                            - ro[i][j] * vs[i][j]);
                }
            }

            writeln!(f_gs, "{} {}", it, s_next).expect("Unable to write!");
            print!("\r[{}] {}", it, s_next);

            if ((s_next - s_prev) / s_prev).abs() < TOL {
                break;
            }
        }
        println!();
        
        for i in 1..NX {
            for j in 1..NY {
                err[i][j] = (vn[i + 1][j] - 2.0 * vn[i][j] + vn[i - 1][j]) / (DELTA * DELTA)
                    + (vn[i][j + 1] - 2.0 * vn[i][j] + vn[i][j - 1]) / (DELTA * DELTA)
                    + ro[i][j] / EPSILON;
                writeln!(
                    f_err,
                    "{} {} {}",
                    i as f64 * DELTA,
                    j as f64 * DELTA,
                    err[i][j]
                )
                .expect("Unable to write!");

                writeln!(
                    f_vn,
                    "{} {} {}",
                    i as f64 * DELTA,
                    j as f64 * DELTA,
                    vn[i][j]
                )
                .expect("Unable to write!");
            }
        }
    }

    // RELAKSACJA LOKALNA

    let omega_ls = [1.0, 1.4, 1.8, 1.9];

    for omega_l in omega_ls {
        let mut v: [[f64; NY + 1]; NX + 1] = [[0.0; NY + 1]; NX + 1];
        for i in 0..=NX {
            v[i][0] = V_1;
        }
        let mut s_prev;
        let mut s_next = 0.0;
        let mut it = 0;

        let f_ls =
            File::create(format!("plots/ls_{}.txt", omega_l)).expect("Unable to create file!");
        let mut f_ls = BufWriter::new(f_ls);

        println!(
            "Calculating with local relaxation for omega_l = {}",
            omega_l
        );
        loop {
            it += 1;

            for i in 1..NX {
                for j in 1..NY {
                    v[i][j] = (1.0 - omega_l) * v[i][j]
                        + 0.25
                            * omega_l
                            * (v[i + 1][j]
                                + v[i - 1][j]
                                + v[i][j + 1]
                                + v[i][j - 1]
                                + DELTA * DELTA * ro[i][j] / EPSILON);
                }
            }

            for j in 1..NY {
                v[0][j] = v[1][j];
                v[NX][j] = v[NX - 1][j];
            }

            s_prev = s_next;
            s_next = 0.0;
            for i in 0..NX {
                for j in 0..NY {
                    s_next += DELTA
                        * DELTA
                        * (0.5 * (v[i + 1][j] - v[i][j]) / DELTA * (v[i + 1][j] - v[i][j]) / DELTA
                            + 0.5 * (v[i][j + 1] - v[i][j]) / DELTA * (v[i][j + 1] - v[i][j])
                                / DELTA
                            - ro[i][j] * v[i][j]);
                }
            }

            writeln!(f_ls, "{} {}", it, s_next).expect("Unable to write!");
            print!("\r[{}] {}", it, s_next);

            if ((s_next - s_prev) / s_prev).abs() < TOL {
                break;
            }
        }
        println!();
    }
}

fn calc_ro(x: f64, y: f64) -> f64 {
    let ro_1 = (-(x - 0.35 * X_MAX) * (x - 0.35 * X_MAX) / (SIGMA_X * SIGMA_X)
        - (y - 0.5 * Y_MAX) * (y - 0.5 * Y_MAX) / (SIGMA_Y * SIGMA_Y))
        .exp();
    let ro_2 = -(-(x - 0.65 * X_MAX) * (x - 0.65 * X_MAX) / (SIGMA_X * SIGMA_X)
        - (y - 0.5 * Y_MAX) * (y - 0.5 * Y_MAX) / (SIGMA_Y * SIGMA_Y))
        .exp();
    ro_1 + ro_2
}
