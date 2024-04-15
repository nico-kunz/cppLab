//
// Created by nicokunz on 4/15/24.
//

#include <iostream>
#include "Complex.hpp"
int main() {
  Complex c = ~Complex(1,2);

  std::cout << c << std::endl;

  c = ~c;
  std::cout << c << std::endl;
}