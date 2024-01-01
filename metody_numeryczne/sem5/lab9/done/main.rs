use indicatif::ProgressBar;
use nalgebra::{DMatrix, SVector};
use std::fs::{self, File};
use std::io::{BufWriter, Write};

const NX: usize = 40;
const NY: usize = 40;
const N: usize = (NX + 1) * (NY + 1);
const DELTA: f64 = 1.0;
const DT: f64 = 1.0;
const TA: f64 = 40.0;
const TB: f64 = 0.0;
const TC: f64 = 30.0;
const TD: f64 = 0.0;
const KB: f64 = 0.1;
const KD: f64 = 0.6;
const IT_MAX: usize = 2000;
const IT_VALUES: [usize; 5] = [100, 200, 500, 1000, 2000];

fn get_l(i: usize, j: usize) -> usize {
    i + j * (NX + 1)
}

fn get_i(l: usize) -> usize {
    l - get_j(l) * (NX + 1)
}

fn get_j(l: usize) -> usize {
    l / (NX + 1)
}

fn assign_t(l: usize, _: usize) -> f64 {
    match get_i(l) {
        0 => TA,
        NX => TC,
        _ => 0.0,
    }
}

fn main() {
    fs::create_dir_all("plots").expect("Unable to create folder plots!");

    let mut a = DMatrix::<f64>::zeros(N, N);
    let mut b = DMatrix::<f64>::zeros(N, N);
    let mut c = SVector::<f64, N>::zeros();
    let mut d;
    let mut t = SVector::<f64, N>::from_fn(assign_t);
    let mut prev_t = SVector::<f64, N>::zeros();

    println!("Filling matrices...");
    let fill_bar = ProgressBar::new(N.try_into().unwrap());
    let (mut l, mut val);
    for i in 0..=NX {
        for j in 0..=NY {
            fill_bar.inc(1);
            l = get_l(i, j);
            match (i, j) {
                (0 | NX, _) => {
                    a[(l, l)] = 1.0;
                    b[(l, l)] = 1.0;
                    c[(l)] = 0.0;
                }
                (1..=NX, NY) if i < NX => {
                    a[(l, l - NX - 1)] = -1.0 / (KB * DELTA);
                    a[(l, l)] = 1.0 + 1.0 / (KB * DELTA);
                    for lj in 0..N {
                        b[(l, lj)] = 0.0;
                    }
                    c[l] = TB;
                }
                (1..=NX, 0) if i < NX => {
                    a[(l, l + NX + 1)] = -1.0 / (KD * DELTA);
                    a[(l, l)] = 1.0 + 1.0 / (KD * DELTA);
                    for lj in 0..N {
                        b[(l, lj)] = 0.0;
                    }
                    c[l] = TD;
                }
                _ => {
                    a[(l, l)] = -2.0 * DT / (DELTA * DELTA) - 1.0;
                    b[(l, l)] = 2.0 * DT / (DELTA * DELTA) - 1.0;
                    val = DT / (2.0 * DELTA * DELTA);
                    a[(l, l - NX - 1)] = val;
                    a[(l, l + NX + 1)] = val;
                    a[(l, l - 1)] = val;
                    a[(l, l + 1)] = val;
                    b[(l, l - NX - 1)] = -val;
                    b[(l, l + NX + 1)] = -val;
                    b[(l, l - 1)] = -val;
                    b[(l, l + 1)] = -val;
                }
            }
        }
    }
    fill_bar.finish();

    println!("Decomposing A...");
    let decomp = a.lu();

    println!("Solving equations...");
    let eq_bar = ProgressBar::new(IT_MAX.try_into().unwrap());
    for it in 0..=IT_MAX {
        eq_bar.inc(1);
        if IT_VALUES.contains(&it) {
            prev_t.clone_from(&t);
        }
        d = &b * t + c;
        t = decomp.solve(&d).expect("Solving equation failed!");
        if IT_VALUES.contains(&it) {
            eq_bar.println(format!("Saving values for it = {}", it));

            let f_t = File::create(format!("plots/t_{}.txt", it))
                .expect(&format!("Unable to create file plots/t_{}.txt!", it)[..]);
            let mut f_t = BufWriter::new(f_t);

            let f_dt = File::create(format!("plots/dt_{}.txt", it))
                .expect(&format!("Unable to create file plots/dt_{}.txt!", it)[..]);
            let mut f_dt = BufWriter::new(f_dt);

            for i in 0..=NX {
                for j in 0..=NY {
                    writeln!(f_t, "{}", t[get_l(i, j)])
                        .expect(&format!("Unable to write to file plots/t_{}.txt!", it)[..]);
                    writeln!(f_dt, "{}", (t[get_l(i, j)] - prev_t[get_l(i, j)]) / DT)
                        .expect(&format!("Unable to write to file plots/dt_{}.txt!", it)[..]);
                }
            }
        }
    }
    eq_bar.finish();
}
