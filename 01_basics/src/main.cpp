//
// Created by nicokunz on 4/15/24.
//

#include <iostream>
#include "Complex.hpp"
int main() {
  Complex x = Complex();
  std::cout << x << std::endl;
  Complex c = ~Complex(1,2);

  std::cout << c << std::endl;

  c = ~c;
  std::cout << c << std::endl;

  Complex a = Complex(1,2);
  Complex b = Complex(1,4);

  c = a + b;
  Complex d = a - b;
  Complex e = a * b;
  Complex f = a / b;
  std::cout << c << std::endl;
  std::cout << d << std::endl;
  std::cout << e << std::endl;
  std::cout << f << std::endl;

  std::cout << c.angle() << std::endl;

  std::cout << Complex::from_euler(3, 0.34906585) << std::endl;

}