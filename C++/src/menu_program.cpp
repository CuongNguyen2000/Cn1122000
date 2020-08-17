#include "../include/menu_program.h"

const int EXIT = 0;

void MenuProgram::run()
{
    bool running = true;
    while (running)
    {
        print_menu();
        int choice = get_option();
        do_task(choice);
        if (choice == EXIT)
            running = false;
    }
}

void MenuProgram::print_menu()
{
}

int MenuProgram::get_option()
{
    bool incorrect = true;
    int choice = 0;
    while (incorrect)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        incorrect = false;
    }
    return choice;
}

void MenuProgram::do_task(const int &choice)
{
}
