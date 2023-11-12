use ndarray::Array2;

use std::fs::File;
use std::io::{BufWriter, Write};

use crate::constants::{get_x, get_y};

pub fn dump_2darray(filename: &str, matrix: &Array2<f64>, k: usize, col_name: Option<&str>) {
    let x_vector = get_x();
    let y_vector = get_y();

    let file_handle = File::create(filename).unwrap();
    let mut out = BufWriter::new(file_handle);

    let last_col_name = col_name.unwrap_or("V");

    writeln!(&mut out, "x,y,{}", last_col_name).unwrap();

    for (i, x) in x_vector.iter().enumerate().step_by(k) {
        for (j, y) in y_vector.iter().enumerate().step_by(k) {
            writeln!(&mut out, "{}, {}, {}", x, y, matrix[(i, j)]).unwrap();
        }
    }
}
