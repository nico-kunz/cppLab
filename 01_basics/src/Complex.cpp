//
// Created by nicokunz on 4/15/24.
//

#include "Complex.hpp"
#include<iostream>
/**
 * Creates Complex number with default values 0 + 0i
 */
Complex::Complex() {
  c_real = 0;
  c_imaginary = 0;
}

Complex::Complex(double real, double imaginary) {
  c_real = real;
  c_imaginary = imaginary;
}

double Complex::real() const {
  return c_real;
}

double Complex::imag() const {
  return c_imaginary;
}

std::ostream& operator<<(std::ostream& out, Complex rhs) {
  out << rhs.c_real << "+" << rhs.c_imaginary << "i";
  return out;
}


