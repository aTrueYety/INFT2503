#pragma once
#include <string>

using namespace std;

const double moms = 0.25;

class Commodity {
  private:
    string name;
    int id;
    double price;
  public:
    Commodity(string name, int id, double price);
    string get_name();
    int get_id();
    double get_price();
    double get_price(double units);
    void set_price(double new_price);
    double get_price_with_sales_tax(double units);
};

void testCommodity();
