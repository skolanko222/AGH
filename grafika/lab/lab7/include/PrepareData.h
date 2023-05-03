#pragma once

void PrepareData(int fun);
float f_wag(float x, float y, float x_w, float y_w);
float interpolacja(float x, float y, const float (*arr)[3], const int wezly);