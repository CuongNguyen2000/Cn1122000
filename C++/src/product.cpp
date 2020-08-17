#include "../include/product.h"

Product::Product()
{
    //Nothing to do
}

Product::Product(const string &id, const string &name, const float &price)
{
    set_id(id);
    set_name(name);
    set_price(price);
    count = 1;
}

void Product::set_id(const string &id)
{
    this->product_id = id;
}

void Product::set_name(const string &name)
{
    this->product_name = name;
}

void Product::set_price(const float &price)
{
    this->product_price = price;
}

string Product::get_id() const
{
    return product_id;
}

string Product::get_name() const
{
    return product_name;
}

float Product::get_price() const
{
    return product_price;
}

void Product::increase_count()
{
    count++;
}

int Product::get_count() const
{
    return count;
}