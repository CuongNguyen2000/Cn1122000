#include <iostream>
#include "../include/cart_program.h"
#include "../include/cart.h"
#include "../include/customer.h"
#include "../include/product.h"
#include "../include/product_infor.h"

using namespace std;

int main(int argc, char *argv[])
{
	string buyer_name;
	string buyer_email;
	cout << "Please enter your name: ";
	cin >> buyer_name;
	cout << "Please enter your email: ";
	cin >> buyer_email;
	CartProgram *c = new CartProgram(buyer_name, buyer_email);
	c->run();
	return 0;
}