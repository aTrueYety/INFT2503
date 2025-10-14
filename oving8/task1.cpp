#include "task1.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void task1() {
  cout << endl << "### Oppgave 1 ###" << endl << endl;
  
  cout << boolalpha;
  
  int x = 5, y = 5;
  std::cout << "equal(" << x << ", " << y << ") = " << equal(x, y) << "\n\n";
  
  double a = 1.20000001, b = 1.2;
  std::cout << "equal(" << std::setprecision(10) << a << ", " << b << ") = " << equal(a, b) << "\n\n";
  
  float f1 = 1.2f, f2 = 1.2f;
  std::cout << "equal(" << f1 << ", " << f2 << ") = " << equal(f1, f2) << "\n";
}

bool equal(double a, double b) {
  cout << "(Bruker spesialutgaven) ";
  std::cout << "Forskjell: " << std::setprecision(10) << std::abs(a - b) << " - ";
  return abs(a - b) < 0.00001;
}

template <typename Type> bool equal(Type a, Type b) {
  cout << "(Bruker template-utgaven) - ";
  return a == b;
}
