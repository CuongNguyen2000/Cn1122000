#include "../include/cart.h"

Cart *Cart::cart = NULL; //static initialization

Cart::Cart() {}

Cart *Cart::get_cart()
{
    if (cart == NULL)
        cart = new Cart();
    return cart;
}

vector<Product> Cart::get_product() const
{
    return products;
}

void Cart::add_product(const string &id, const string &name, const float &price)
{
    Product pr(id, name, price);
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].get_id() == id)
        {
            products[i].increase_count();
            return;
        }
    }
    products.push_back(pr);
}

void Cart::delete_product(const string &id)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].get_id() == id)
        {
            products.erase(products.begin() + i);
            return;
        }
    }
    cout << "*--------------------------------------------------*" << endl;
    cout << "|   Product does not exist in your shopping cart   |" << endl;
    cout << "*--------------------------------------------------*" << endl;
}

int Cart::count_product() const
{
    int count = 0;
    for (int i = 0; i < products.size(); i++)
    {
        count += products[i].get_count();
    }
    return count;
}

bool Cart::is_empty() const
{
    if (products.empty())
        return true;
    return false;
}

void Cart::show_cart() const
{
    cout << "*********************** YOUR SHOPPING CART *************************" << endl;
    printf("+-----+-------+------------------------------+----------+----------+\n");
    printf("|%5s|%7s|%30s|%10s|%10s|\n", "No.", "ID", "Name", "Price", "Amount");
    printf("+-----+-------+------------------------------+----------+----------+\n");
    for (int i = 0; i < products.size(); i++)
    {
        printf("|%5d|%7s|%30s|%.2f     |%10d|\n", i + 1, products[i].get_id().c_str(), products[i].get_name().c_str(), products[i].get_price(), products[i].get_count());
    }
    printf("+-----+-------+------------------------------+----------+----------+\n");
    cout << "*~~~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~*" << endl;
    cout << "|  Total of Products  |    " << count_product() << endl;
    cout << "*~~~~~~~~~~~~~~~~~~~~~*~~~~~~~~~~*" << endl;
}