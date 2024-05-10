//
// Created by nicokunz on 4/15/24.
//

#ifndef INC_01_BASICS_SRC_COMPLEX_HPP_
#define INC_01_BASICS_SRC_COMPLEX_HPP_

#include<iostream>
class Complex {
 public:
  Complex();
  Complex(double real, double imaginary);
  static Complex from_euler(double abs, double angle);
  double real() const;
  double imag() const;
  double abs() const;
  double angle() const;

  Complex operator~() const;
  Complex operator+(Complex rhs) const;
  Complex operator-(Complex rhs) const;
  Complex operator*(Complex rhs) const;
  Complex operator/(Complex rhs) const;

  friend std::ostream& operator<<(std::ostream&, Complex);

 private:
  double c_real;
  double c_imaginary;

};

#endif //INC_01_BASICS_SRC_COMPLEX_HPP_
