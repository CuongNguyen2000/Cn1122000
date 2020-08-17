#include "../include/product_infor.h"

ProductInfor::ProductInfor()
{
    if (product_infor.empty())
        add_available_infor();
}

vector<Product> ProductInfor::get_infor() const
{
    return product_infor;
}

void ProductInfor::add_available_infor()
{
    Product items[4] = {
        {"A001", "Samsung Galaxy Note20 Ultra", 30.5},
        {"A002", "Iphone XS Max", 20.6},
        {"B001", "Samsung Galaxy Fold", 35.8},
        {"B002", "Huawei Mate 30 Pro", 27.8}};

    for (int i = 0; i < 4; i++)
    {
        product_infor.push_back(items[i]);
    }
}