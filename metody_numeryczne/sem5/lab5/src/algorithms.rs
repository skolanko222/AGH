use ndarray::Array2;

use crate::constants::PARAMETERS;

pub fn integrate_s(k: usize, v: &Array2<f64>) -> f64 {
    let nx = PARAMETERS.nx;
    let ny = PARAMETERS.ny;
    let delta = PARAMETERS.delta;

    let mut sum = 0.;

    let begin_fraction = (k as f64 * delta).powi(2) / 2.;
    let divider = k as f64 * 2. * delta;

    for i in (0usize..nx).step_by(k) {
        for j in (0usize..ny).step_by(k) {
            let first_fraction = (v[(i + k, j)] - v[(i, j)]) / divider;
            let second_fraction = (v[(i + k, j + k)] - v[(i, j + k)]) / divider;
            let first_square = (first_fraction + second_fraction).powi(2);

            let third_fraction = (v[(i, j + k)] - v[(i, j)]) / divider;
            let fourth_fraction = (v[(i + k, j + k)] - v[(i + k, j)]) / divider;
            let second_square = (third_fraction + fourth_fraction).powi(2);

            sum += begin_fraction * (first_square + second_square);
        }
    }

    return sum;
}

pub fn relaxate_once(k: usize, v: &mut Array2<f64>) {
    let nx = PARAMETERS.nx;
    let ny = PARAMETERS.ny;

    for i in (k..nx).step_by(k) {
        for j in (k..ny).step_by(k) {
            v[(i, j)] = 0.25 * (v[(i + k, j)] + v[(i - k, j)] + v[(i, j + k)] + v[(i, j - k)]);
        }
    }
}

pub fn to_dense_mesh(k: usize, v: &mut Array2<f64>) {
    assert!(k > 1 && k % 2 == 0, "Invalid k parameter");

    let nx = PARAMETERS.nx;
    let ny = PARAMETERS.ny;

    let k2 = k / 2;

    for i in (0..nx).step_by(k) {
        for j in (0..ny).step_by(k) {
            v[(i + k2, j + k2)] =
                0.25 * (v[(i, j)] + v[(i + k, j)] + v[(i, j + k)] + v[(i + k, j + k)]);
            if i != nx - k {
                v[(i + k, j + k2)] = 0.5 * (v[(i + k, j)] + v[(i + k, j + k)]);
            }

            if j != ny - k {
                v[(i + k2, j + k)] = 0.5 * (v[(i, j + k)] + v[(i + k, j + k)]);
            }

            if j != 0 {
                v[(i + k2, j)] = 0.5 * (v[(i, j)] + v[(i + k, j)]);
            }

            if i != 0 {
                v[(i, j + k2)] = 0.5 * (v[(i, j)] + v[(i, j + k)]);
            }
        }
    }
}
