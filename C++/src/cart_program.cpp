#include "../include/cart_program.h"
#include "../include/cart.h"
#include "../include/customer.h"
#include "../include/product.h"
#include "../include/product_infor.h"

CartProgram::CartProgram(const string &name, const string &email)
{
    items_infor = new ProductInfor;
    products = items_infor->get_infor();
    customer = new Customer(name, email);
}

void CartProgram::print_menu()
{
    cout << "+-----------------------------------------------------+" << endl;
    cout << "***                 **** MENU ****                  ***" << endl;
    cout << "+-----------------------------------------------------+" << endl;
    cout << "***              FUNCTION              ***  CHOICE  ***" << endl;
    cout << "+-----------------------------------------------------+" << endl;
    cout << "***     List all available product     ***     " << LIST_PRODUCT << "    ***" << endl;
    cout << "+-----------------------------------------------------+" << endl;
    cout << "***     Add Product from list          ***     " << ADD_PRODUCT_FROM_LIST << "    ***" << endl;
    cout << "+-----------------------------------------------------+" << endl;
    cout << "***     Delete product                 ***     " << DELETE_PRODUCT << "    ***" << endl;
    cout << "+-----------------------------------------------------+" << endl;
    cout << "***     Show Cart of customer          ***     " << SHOW_CART << "    ***" << endl;
    cout << "+-----------------------------------------------------+" << endl;
    cout << "***     EXIT THE PROGRAM               ***     0    ***" << endl;
    cout << "+-----------------------------------------------------+" << endl;
}

void CartProgram::do_task(const int &choice)
{
    switch (choice)
    {
    case LIST_PRODUCT:
        list_product();
        break;
    case ADD_PRODUCT_FROM_LIST:
        add_product_from_list();
        break;
    case DELETE_PRODUCT:
        delete_product();
        break;
    case SHOW_CART:
        show_cart();
        break;
    case 0:
        printMess("See you again!!!");
        break;

    default:
        printMess("Invalid option. Plz choose again!!!");
        break;
    }
}

void CartProgram::printMess(const string &mess) const
{
    cout << mess << endl;
}

void CartProgram::list_product()
{
    cout << endl;
    printf("+-----+-------+------------------------------+----------+\n");
    printf("|%5s|%7s|%30s|%10s|\n", "No.", "ID", "Name", "Price");
    printf("+-----+-------+------------------------------+----------+\n");
    for (int i = 0; i < products.size(); i++)
    {
        printf("|%5d|%7s|%30s|%.2f     |\n", i + 1, products[i].get_id().c_str(), products[i].get_name().c_str(), products[i].get_price());
    }
    printf("+-----+-------+------------------------------+----------+\n");
    cout << endl;
}

void CartProgram::add_product_from_list()
{
    list_product();
    bool isCorrect = true;
    do
    {
        cout << "Please select one of the above products to add to your shopping cart: ";
        int select;
        cin >> select;
        cout << endl;

        if (select > 0 && select <= 4)
        {
            customer->add_new_product(products[select - 1].get_id(), products[select - 1].get_name(), products[select - 1].get_price());
            cout << "+------------------------------+" << endl;
            cout << "|   Add product successfully   |" << endl;
            cout << "+------------------------------+" << endl;
            cout << endl;
        }
        else
        {
            cout << "+---------------------------------+" << endl;
            cout << "|   This product does not exist   |" << endl;
            cout << "+---------------------------------+" << endl;
            cout << endl;
        }

        int x = 0;
        do
        {
            x = enterx();
            int isContinue = enter_new_product(x);
            if (isContinue == -1)
                return;
            else
                isCorrect = isContinue == 1;
        } while (isCorrect == false);
    } while (isCorrect);
}

int CartProgram::enter_new_product(const int &x)
{
    int isCorrect = 1;
    switch (x)
    {
    case 1:
        isCorrect = 1;
        break;
    case 0:
        isCorrect = -1;
        break;
    default:
        cout << endl;
        printMess("Invalid input !!! Please try again !!!");
        cout << endl;
        isCorrect = 0;
        break;
    }
    return isCorrect;
}

int CartProgram::enterx()
{
    int x = 0;
    bool valid = false;
    cout << "+------------------------------------------+" << endl;
    cout << "|    WOULD YOU LIKE TO ADD MORE PRODUCT?   |" << endl;
    cout << "+------------------------------------+-----+" << endl;
    cout << "|        Add more product            |  1  |" << endl;
    cout << "+------------------------------------+-----+" << endl;
    cout << "|        Back to menu                |  0  |" << endl;
    cout << "+------------------------------------+-----+" << endl;

    while (!valid)
    {
        cout << "Enter your choice: ";
        cin >> x;
        valid = true;
    }
    return x;
}

void CartProgram::delete_product()
{
    customer->show_cart();
    cout << endl;
    cout << "Select the product you want to remove: ";
    int select_del;
    cin >> select_del;
    cout << endl;

    if (select_del > 0)
    {
        vector<Product> pr = customer->get_product_cart();
        customer->take_out_product(pr[select_del - 1].get_id());
    }
}

void CartProgram::show_cart()
{
    customer->show_cart();
    cout << endl;
}