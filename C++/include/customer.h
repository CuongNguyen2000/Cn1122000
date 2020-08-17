#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include "cart.h"

class Customer
{
private:
    Cart *cart;
    string name;
    string email;

public:
    Customer();
    Customer(const string &name, const string &email);
    void add_new_product(const string &product_id, const string &product_name, const float &product_price);
    void take_out_product(const string &product_id);
    void show_cart() const;
    vector<Product> get_product_cart() const;
};

#endif