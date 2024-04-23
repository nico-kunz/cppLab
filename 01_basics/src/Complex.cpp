//
// Created by nicokunz on 4/15/24.
//

#include "Complex.hpp"
#include <iostream>
#include <cmath>
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

double Complex::abs() const {
  return sqrt(c_real*c_real + c_imaginary*c_imaginary);
}

double Complex::angle() const {
  return atan2(c_imaginary, c_real);
}

Complex Complex::operator~() const {
  return {c_real, c_imaginary * -1};
}

Complex Complex::operator+(Complex rhs) const {
  return {c_real + rhs.c_real, c_imaginary + rhs.c_imaginary};
}

Complex Complex::operator-(Complex rhs) const {
  return {c_real - rhs.c_real, c_imaginary - rhs.c_imaginary};
}

Complex Complex::operator*(Complex rhs) const {
  const double new_real = c_real*rhs.c_real - c_imaginary*rhs.c_imaginary;
  const double new_imaginary = c_real*rhs.c_imaginary + c_imaginary*rhs.c_real;

  return {new_real, new_imaginary};
}

Complex Complex::operator/(Complex rhs) const {
  const double denominator = rhs.c_imaginary*rhs.c_imaginary + rhs.c_real*rhs.c_real;
  const double new_real = (c_real*rhs.c_real + c_imaginary*rhs.c_imaginary) / denominator;
  const double new_imaginary = (c_imaginary*rhs.c_real - c_real*rhs.c_imaginary) / denominator;

  return {new_real, new_imaginary};
}

std::ostream& operator<<(std::ostream& out, Complex rhs) {
  std::string sign = rhs.c_imaginary >= 0 ? "+" : "";
  out << rhs.c_real << sign << rhs.c_imaginary << "i";
  return out;
}
Complex Complex::from_euler(double abs, double angle) {
  return {abs*cos(angle), abs*sin(angle)};
}


