#include "Numerik.hpp"

double trapz(double (*fx)(double), double a, double b, size_t n) {
double interval_len = (b-a)/n;
double sum = 0.0;

for(int i = 1; i < n; ++i) {
sum += fx(a + i*interval_len);
}

return interval_len * ((fx(b) + fx(a))/2 + sum);
}