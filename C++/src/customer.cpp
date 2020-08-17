#include "../include/customer.h"

Customer::Customer()
{
}

Customer::Customer(const string &name, const string &email)
{
    this->name = name;
    this->email = email;
    cart = Cart::get_cart();
}

void Customer::add_new_product(const string &product_id, const string &product_name, const float &product_price)
{
    cart->add_product(product_id, product_name, product_price);
}

void Customer::take_out_product(const string &product_id)
{
    cart->delete_product(product_id);
}

void Customer::show_cart() const
{
    cout << endl;
    cout << "Customer name: " << name << endl;
    cout << "Customer email: " << email << endl;
    cout << endl;
    cart->show_cart();
}

vector<Product> Customer::get_product_cart() const
{
    return cart->get_product();
}