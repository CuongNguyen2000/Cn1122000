#ifndef _CART_PROGRAM_H_
#define _CART_PROGRAM_H_

#include "menu_program.h"
#include "product.h"
#include "product_infor.h"
#include "customer.h"

#include <vector>

#define LIST_PRODUCT 1
#define ADD_PRODUCT_FROM_LIST 2
#define DELETE_PRODUCT 3
#define SHOW_CART 4
#define EXIT_PROGRAM 0

class CartProgram : public MenuProgram
{
private:
    ProductInfor *items_infor;
    vector<Product> products;
    Customer *customer;

public:
    CartProgram(const string &name, const string &email);

protected:
    void print_menu();
    void do_task(const int &choice);
    void printMess(const string &mess) const;

private:
    void list_product();
    void add_product_from_list();
    void delete_product();
    void show_cart();
    int enterx();
    int enter_new_product(const int &x);
};

#endif