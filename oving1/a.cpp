#include "a.hpp"
#include <iostream>

const int length = 5;
double temp;
int over;
int between;
int under;

void a() {
  std::cout << "Du skal skrive inn 5 temperaturer. \n";
  
  for (int i = 0; i < length; i++) {
    std::cout << "Temperatur nr " << i + 1 << ": ";
    std::cin >> temp;
    
    if (temp > 20) {
      over++;
    } else if (temp < 10) {
      under++;
    } else {
      between++;
    }
  }
  
  std::cout << over << " temperaturer over 20 grader" << "\n";
  std::cout << between << " temperaturer mellom 20 og 10 grader" << "\n";
  std::cout << under << " temperaturer under 10 grader" << "\n";
}
