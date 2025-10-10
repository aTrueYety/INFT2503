#include "task1.hpp"
#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

void task1() {
  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;

  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b);
  
  
  cout << endl << "testing a - 5:" << endl;
  print("a = ", a);
  b = a - 5;
  print("c = ", b);
  
  cout << endl << "testing 5 - a:" << endl;
  print("a = ", a);
  b = 5 - a;
  print("c = ", b);
}

// Utskrift:
// a = 1 / 2
// b = 3 / 4
// c = 5 / 1
// d = 2 / 3
// b = 5 / 4
// c = 6 / 1
// d = 4 / 9
// c = -55 / 36
// a + b != c + d
// b = 1 / 4
