#ifndef RESALEPRODUCT_H
#define RESALEPRODUCT_H

#include "Product.h"
#include <iostream>
#include <iomanip>

using namespace std;

class ResaleProduct : public Product
{
    private:

        int profit_margin;
    
    public:

        ResaleProduct(int id, float price, int profit_margin) : Product(Product(id, price)), profit_margin(profit_margin) { }; 

        float get_sell_price() const override { return this->price_ + this->price_ * this->profit_margin / 100.0f; };

        int get_profit_margin() const { return this->profit_margin; };

        void set_profit_margin(int margin) { this->profit_margin = margin; };

};

int main()
{
{ const ResaleProduct p1(10001, 2.5f, 10);
  cout << fixed << setprecision(2)
       << p1.get_id() << ' ' 
       << p1.get_profit_margin() << ' ' 
       << p1.get_sell_price() << endl; }
{ ResaleProduct p1(10002, 10, 0);
  p1.set_profit_margin(30);
  cout << fixed << setprecision(2)
       << p1.get_id() << ' ' 
       << p1.get_profit_margin() << ' ' 
       << p1.get_sell_price() << endl; }
{ const Product& p1 = ResaleProduct(10003, 2.75f, 100);
  cout << fixed << setprecision(2)
       << p1.get_id() << ' ' 
       << p1.get_sell_price() << endl; }
{ const Product& p1 = ResaleProduct(10004, 100.90f, 50);
  cout << fixed << setprecision(2)
       << p1.get_id() << ' ' 
       << p1.get_sell_price() << endl; }
    return 0;
}

#endif