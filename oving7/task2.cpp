#include "task2.hpp"

#include <iostream>
#include <vector>
#include <algorithm>


Set::Set() {};

Set::Set(const Set &other) {
  table = other.table;
}

Set::Set(std::vector<int> _table) {
  table = _table;
}

Set &Set::operator+=(int x) {
  for (auto i : table) {
    if (i == x) return *this;
  }
  table.push_back(x);
  return *this;
}

Set Set::operator+(const Set &other) const {
  Set res = Set(table);
  for (auto i : other.table) res += i;
  return res;
}

Set Set::operator+(const int x) const {
  for (auto i : table) if (x == i) {
      return Set(table);
  }
  Set res = Set(table);
  res.table.push_back(x);  
  return res;
};

Set &Set::operator=(const Set &other) {
  table = other.table;
  return *this;
}

void Set::print() {
  std::cout << "{";
  for (size_t i = 0; i < table.size(); ++i) {
    std::cout << table[i];
    if (i != table.size() - 1) std::cout << ", ";
  }
  std::cout << "}" << std::endl;
}

Set operator+(int x, const Set &s) {
  return s + x; // reuse your existing Set + int logic
}

void task2() {
  // Test 1: Constructing sets
  Set a({1, 2, 3});
  Set b({3, 4, 5});
  std::cout << "Set a: ";
  a.print(); // {1, 2, 3}
  std::cout << "Set b: ";
  b.print(); // {3, 4, 5}
  
  // Test 2: Set + Set
  Set c = a + b;
  std::cout << "Set c = a + b: ";
  c.print(); // {1, 2, 3, 4, 5}
  
  // Test 3: Set + int
  Set d = c + 6;
  std::cout << "Set d = c + 6: ";
  d.print(); // {1, 2, 3, 4, 5, 6}
  
  // Test 4: int + Set (if implemented)
  Set e = 7 + d;
  std::cout << "Set e = 7 + d: ";
  e.print(); // {1, 2, 3, 4, 5, 6, 7}
  
  // Test 5: Duplicate int addition
  Set f = e + 3;
  std::cout << "Set f = e + 3 (duplicate): ";
  f.print(); // Should be unchanged from e
  
  // Test 6: Assignment operator
  Set g;
  g = f;
  std::cout << "Set g = f: ";
  g.print(); // Same as f
}
