#pragma once

#include <cstddef>

double trapz(double (*fx)(double), double a, double b, size_t n);

template <typename T>
T fxT(T x) {
    return x * x * x + T{4}*(x * x) - T{7}*x + T{12};
}

template <typename T>
T trapzT(T (*fx)(T), T a, T b, size_t n) {
    T interval_len = (b-a)/n;
    T sum = T{};

    for(int i = 1; i < n; ++i) {
        sum += fx(a + i*interval_len);
    }

    return interval_len * (0.5*(fx(b) + fx(a)) + sum);
}
