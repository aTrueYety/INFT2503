#include "b.hpp"
#include <iostream>
#include <fstream>
  
  
void read_temperatures(double temperatures[], int length) {
  
  std::ifstream infile("data.txt");
  if (!infile) {
    std::cerr << "Error opening file!" << std::endl;
    return;
  }
  
  char sep;
  for (int i = 0; i < length; i++) {
    infile >> temperatures[i];
    std::cout << "Temperatur " << i + 1 << ": " << temperatures[i] << std::endl;
    infile >> sep;
  }
  
  infile.close();
  
}
