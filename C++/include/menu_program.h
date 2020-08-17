#ifndef _MENU_PROGRAM_H_
#define _MENU_PROGRAM_H_

#include <iostream>
#include <string>

using namespace std;

class MenuProgram
{
public:
    void run();

protected:
    int get_option();
    virtual void print_menu() = 0;               //abs method
    virtual void do_task(const int &choice) = 0; //abs method
};

#endif