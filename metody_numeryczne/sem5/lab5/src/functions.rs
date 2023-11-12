use std::f64::consts::PI;

use ndarray::prelude::Array2;

use crate::constants::{get_x, get_y, PARAMETERS};

pub fn vb_1(y: f64) -> f64 {
    (PI * (y / PARAMETERS.y_max)).sin()
}

pub fn vb_2(x: f64) -> f64 {
    -(2. * PI * (x / PARAMETERS.x_max)).sin()
}

pub fn vb_3(y: f64) -> f64 {
    (PI * (y / PARAMETERS.y_max)).sin()
}

pub fn vb_4(x: f64) -> f64 {
    (2. * PI * (x / PARAMETERS.x_max)).sin()
}

pub fn make_edges(matrix: &mut Array2<f64>) {
    let x_arr = get_x();
    let y_arr = get_y();

    // VB_1, VB_3
    for (y_index, y) in y_arr.iter().enumerate() {
        let value_b1 = vb_1(*y);
        let value_b3 = vb_3(*y);
        matrix[(0, y_index)] = value_b1;
        matrix[(x_arr.len() - 1, y_index)] = value_b3;
    }

    // VB_2, VB_4
    for (x_index, x) in x_arr.iter().enumerate() {
        let value_b2 = vb_2(*x);
        let value_b4 = vb_4(*x);
        matrix[(x_index, y_arr.len() - 1)] = value_b2;
        matrix[(x_index, 0)] = value_b4;
    }
}
