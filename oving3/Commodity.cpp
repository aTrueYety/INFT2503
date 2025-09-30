#include "Commodity.hpp"
#include <iostream>
using namespace std;

Commodity::Commodity(string name, int id, double price) {
    this->name = name;
    this->id = id;
    this->price = price;
}
string Commodity::get_name() {
    return name;
}
int Commodity::get_id() {
    return id;
}
double Commodity::get_price(double units) {
    return price * units;
}
double Commodity::get_price() {
    return price;
}
void Commodity::set_price(double new_price) {
    price = new_price;
}
double Commodity::get_price_with_sales_tax(double units) {
    return (price * (1 + moms)) * units;
}

void testCommodity() {
  const double quantity = 2.5;
  Commodity commodity("Norvegia", 123, 73.50);
  
  cout << "Varenavn: " << commodity.get_name() << ", varenr: " << commodity.get_id()
       << " Pris pr enhet: " << commodity.get_price() << endl;
  
  cout << "Kilopris: " << commodity.get_price() << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity)
       << " uten moms" << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity)
       << " med moms" << endl;
  
  commodity.set_price(79.60);
  cout << "Ny kilopris: " << commodity.get_price() << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity)
       << " uten moms" << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity)
       << " med moms" << endl;
}
