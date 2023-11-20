#include <iostream>
#include <fstream>
#include <cmath>
#include <array>

const double EPSILON = 1.0;
const double DELTA = 0.1;
const int NX = 150;
const int NY = 100;
const double V_1 = 10.0;
const double X_MAX = DELTA * NX;
const double Y_MAX = DELTA * NY;
const double SIGMA_X = 0.1 * X_MAX;
const double SIGMA_Y = 0.1 * Y_MAX;
const double TOL = 1e-8;

void calculate_ro(double ro[NX + 1][NY + 1]) {
    for (int i = 0; i <= NX; ++i) {
        for (int j = 0; j <= NY; ++j) {
            ro[i][j] = exp(-pow((i * DELTA - 0.35 * X_MAX) / SIGMA_X, 2)
                          - pow((j * DELTA - 0.5 * Y_MAX) / SIGMA_Y, 2))
                        - exp(-pow((i * DELTA - 0.65 * X_MAX) / SIGMA_X, 2)
                              - pow((j * DELTA - 0.5 * Y_MAX) / SIGMA_Y, 2));
        }
    }
}

void global_relaxation(double omega_g, std::ofstream &f_gs, std::ofstream &f_vn, std::ofstream &f_err) {
    double vs[NX + 1][NY + 1] = {{0.0}};
    double vn[NX + 1][NY + 1] = {{0.0}};
    double ro[NX + 1][NY + 1] = {{0.0}};
    double err[NX][NY] = {{0.0}};
    double s_prev, s_next = 0.0;
    int it = 0;

    calculate_ro(ro);

    for (int i = 0; i <= NX; ++i) {
        vs[i][0] = V_1;
        vn[i][0] = V_1;
    }

    do {
        ++it;

        for (int i = 1; i < NX; ++i) {
            for (int j = 1; j < NY; ++j) {
                vn[i][j] = 0.25 * (vs[i + 1][j] + vs[i - 1][j] + vs[i][j + 1] + vs[i][j - 1]
                                   + DELTA * DELTA * ro[i][j] / EPSILON);
            }
        }

        for (int j = 1; j < NY; ++j) {
            vn[0][j] = vn[1][j];
            vn[NX][j] = vn[NX - 1][j];
        }

        for (int i = 0; i <= NX; ++i) {
            for (int j = 0; j <= NY; ++j) {
                vs[i][j] = (1.0 - omega_g) * vs[i][j] + omega_g * vn[i][j];
            }
        }

        s_prev = s_next;
        s_next = 0.0;

        for (int i = 0; i < NX; ++i) {
            for (int j = 0; j < NY; ++j) {
                s_next += DELTA * DELTA
                          * (0.5 * pow((vs[i + 1][j] - vs[i][j]) / DELTA, 2)
                             + 0.5 * pow((vs[i][j + 1] - vs[i][j]) / DELTA, 2)
                             - ro[i][j] * vs[i][j]);
            }
        }

        f_gs << it << " " << s_next << "\n";
        std::cout << "\r[" << it << "] " << s_next << std::flush;

        if (std::abs((s_next - s_prev) / s_prev) < TOL) {
            break;
        }
    } while (true);

    std::cout << std::endl;

    for (int i = 1; i < NX; ++i) {
        for (int j = 1; j < NY; ++j) {
            err[i][j] = (vn[i + 1][j] - 2.0 * vn[i][j] + vn[i - 1][j]) / (DELTA * DELTA)
                      + (vn[i][j + 1] - 2.0 * vn[i][j] + vn[i][j - 1]) / (DELTA * DELTA)
                      + ro[i][j] / EPSILON;

            f_err << i * DELTA << " " << j * DELTA << " " << err[i][j] << "\n";
            f_vn << i * DELTA << " " << j * DELTA << " " << vn[i][j] << "\n";
        }
    }
}

void local_relaxation(double omega_l, std::ofstream &f_ls) {
    double v[NX + 1][NY + 1] = {{0.0}};
    double ro[NX + 1][NY + 1] = {{0.0}};
    double s_prev, s_next = 0.0;
    int it = 0;

    calculate_ro(ro);

    for (int i = 0; i <= NX; ++i) {
        v[i][0] = V_1;
    }

    do {
        ++it;

        for (int i = 1; i < NX; ++i) {
            for (int j = 1; j < NY; ++j) {
                v[i][j] = (1.0 - omega_l) * v[i][j]
                        + 0.25 * omega_l * (v[i + 1][j] + v[i - 1][j] + v[i][j + 1] + v[i][j - 1]
                                           + DELTA * DELTA * ro[i][j] / EPSILON);
            }
        }

        for (int j = 1; j < NY; ++j) {
            v[0][j] = v[1][j];
            v[NX][j] = v[NX - 1][j];
        }

        s_prev = s_next;
        s_next = 0.0;

        for (int i = 0; i < NX; ++i) {
            for (int j = 0; j < NY; ++j) {
                s_next += DELTA * DELTA
                          * (0.5 * pow((v[i + 1][j] - v[i][j]) / DELTA, 2)
                             + 0.5 * pow((v[i][j + 1] - v[i][j]) / DELTA, 2)
                             - ro[i][j] * v[i][j]);
            }
        }

        f_ls << it << " " << s_next << "\n";
        std::cout << "\r[" << it << "] " << s_next << std::flush;

        if (std::abs((s_next - s_prev) / s_prev) < TOL) {
            break;
        }
    } while (true);

    std::cout << std::endl;
}

int main() {

    double omega_gs[] = {0.6, 1.0};
    for (double omega_g : omega_gs) {
        std::ofstream f_gs("gs_" + std::to_string(omega_g) + ".txt");
        std::ofstream f_vn("vn_" + std::to_string(omega_g) + ".txt");
        std::ofstream f_err("err_" + std::to_string(omega_g) + ".txt");

        std::cout << "Calculating with global relaxation for omega_g = " << omega_g << std::endl;
        global_relaxation(omega_g, f_gs, f_vn, f_err);

        f_gs.close();
        f_vn.close();
        f_err.close();
    }

    double omega_ls[] = {1.0, 1.4, 1.8, 1.9};
    for (double omega_l : omega_ls) {
        std::ofstream f_ls("ls_" + std::to_string(omega_l) + ".txt");

        std::cout << "Calculating with local relaxation for omega_l = " << omega_l << std::endl;
        local_relaxation(omega_l, f_ls);

        f_ls.close();
    }

    return 0;
}