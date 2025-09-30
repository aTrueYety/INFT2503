#include <iostream>
#include <cstring>

int find_sum(const int *table, int length) {
  int res = 0;
  for (int i = 0; i < length; i++) {
    res += table[i];    
  }
  return res;
}

int main() {
  int nums[20];
  for (int i = 0; i < 20; i++) { nums[i] = i + 1; }
  
  /*
   * Prøvde å vise litt ulike måter å bruke funksjonen mtp
   * pointers og adresser.
   */
  std::cout
    << "10 første: "
    << find_sum(nums, 10)
    << std::endl;
  std::cout
    << "5  neste:  "
    << find_sum(&nums[10], 5)
    << std::endl;
  std::cout
    << "5  siste:  "
    << find_sum(nums, 20) - find_sum(nums, 15)
    << std::endl;
}
