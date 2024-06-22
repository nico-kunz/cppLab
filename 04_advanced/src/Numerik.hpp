#pragma once

#include <cstddef>

template <typename F>
double trapz(F fx, double a, double b, size_t n) {
    return 0.0;
}

template <typename T>
T fxT(T x) {
    return 0;
}

template <typename T, typename F>
T trapzT(F fx, T a, T b, size_t n) {
    return 0;
}
