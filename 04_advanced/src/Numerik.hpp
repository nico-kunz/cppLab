#pragma once

#include <cstddef>

double trapz(double (*fx)(double), double a, double b, size_t n) {
    double interval_len = (b-a)/n;
    double sum = 0.0;

    for(int i = 1; i < n; ++i) {
        sum += fx(a + i*interval_len);
    }

    return interval_len * ((fx(b) + fx(a))/2 + sum);
}

template <typename T>
T fxT(T x) {
    return x * x * x + 4*(x * x) - T{7}*x + T{12};
}

template <typename T>
T trapzT(T (*fx)(T), T a, T b, size_t n) {
    T interval_len = (b-a)/n;
    T sum = T{};

    for(int i = 1; i < n; ++i) {
        sum += fx(a + i*interval_len);
    }

    return interval_len * ((fx(b) + fx(a))/2 + sum);
}
