#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
    string product_id;
    string product_name;
    float product_price;
    int count;

public:
    Product();
    Product(const string &id, const string &name, const float &price);

    // Get method
    string get_id() const;
    string get_name() const;
    float get_price() const;
    // Set method
    void set_id(const string &id);
    void set_name(const string &name);
    void set_price(const float &price);

    void increase_count();
    int get_count() const;
};

#endif