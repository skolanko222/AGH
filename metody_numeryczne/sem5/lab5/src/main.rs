use functions::make_edges;
use ndarray::prelude::*;
use std::fs::File;
use std::io::{BufWriter, Write};

mod constants;
use constants::{get_z, K, PARAMETERS};

mod data_dump;
mod functions;

mod algorithms;
use algorithms::{integrate_s, relaxate_once, to_dense_mesh};

use crate::data_dump::dump_2darray;

type Arr = Array2<f64>;

const DATA_DIR: &'static str = "data";

fn setup_workspace() {
    std::fs::create_dir_all(&DATA_DIR)
        .expect(format!("Cannot crate directory, {}", &DATA_DIR).as_str());

    std::env::set_current_dir(&DATA_DIR).unwrap();
}

fn main() {
    //setup_workspace();

    let k_values = K.to_owned();
    let tol = PARAMETERS.TOL;

    let mut v: Arr = get_z();

    make_edges(&mut v);

    //print V to consol
    // println!("V = {:?}", v);

    let mut iteration = 0;
    for k in k_values {
        println!("Calculating for k={}", k);

        let file_s = File::create(format!("s_{}.csv", k)).unwrap();
        let mut writter_s = BufWriter::new(file_s);
        writeln!(writter_s, "iter, s").unwrap();
        let mut s_prev = integrate_s(k, &v);
        writeln!(writter_s, "{}, {}", iteration, s_prev).unwrap();

        loop {
            iteration += 1;
            relaxate_once(k, &mut v);

            let s = integrate_s(k, &v);
            writeln!(writter_s, "{}, {}", iteration, s).unwrap();

            if ((s - s_prev) / s_prev).abs() < tol {
                break;
            }

            s_prev = s;
        }

        if k != 1 {
            to_dense_mesh(k, &mut v);
        }

        dump_2darray(format!("v_{}.csv", k).as_str(), &v, k, Some("V"));
    }
}
