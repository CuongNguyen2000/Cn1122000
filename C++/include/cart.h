#ifndef _CART_H_
#define _CART_H_

#include "product.h"
#include <vector>

class Cart
{
private:
    vector<Product> products;
    static Cart *cart;
    Cart();

public:
    static Cart *get_cart();
    vector<Product> get_product() const;
    void add_product(const string &id, const string &name, const float &price);
    void delete_product(const string &id);
    int count_product() const;
    bool is_empty() const;
    void show_cart() const;
};

#endif