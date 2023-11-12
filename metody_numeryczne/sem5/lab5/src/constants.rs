use ndarray::prelude::*;

#[allow(non_snake_case)]
#[derive(Debug)]
pub struct Domain {
    pub delta: f64,
    pub nx: usize,
    pub ny: usize,
    pub x_max: f64,
    pub y_max: f64,
    pub TOL: f64,
}

pub const PARAMETERS: Domain = {
    const DELTA: f64 = 0.2;
    const N: f64 = 128.;
    Domain {
        delta: DELTA,
        nx: N as usize,
        ny: N as usize,
        x_max: DELTA * N,
        y_max: DELTA * N,
        TOL: 1e-8,
    }
};

pub const K: &'static [usize] = &[16, 8, 4, 2, 1];

pub fn get_x() -> Array1<f64> {
    let mut vec = Array1::<f64>::zeros(PARAMETERS.nx + 1);
    for (i, x) in vec.iter_mut().enumerate() {
        *x = i as f64 * PARAMETERS.delta;
    }

    return vec;
}

pub fn get_y() -> Array1<f64> {
    let mut vec = Array1::<f64>::zeros(PARAMETERS.ny + 1);
    for (j, y) in vec.iter_mut().enumerate() {
        *y = j as f64 * PARAMETERS.delta;
    }

    return vec;
}

pub fn get_z() -> Array2<f64> {
    Array2::<f64>::zeros((PARAMETERS.nx + 1, PARAMETERS.ny + 1))
}
