#ifndef _PRODUCT_INFORMATION_H_
#define _PRODUCT_INFORMATION_H_

#include "product.h"
#include <vector>

class ProductInfor
{
private:
    vector<Product> product_infor;

public:
    ProductInfor();
    vector<Product> get_infor() const;
    void add_available_infor();
};

#endif