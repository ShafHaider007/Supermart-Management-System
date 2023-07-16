#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;

class Menu
{
public:
    void MainMenu()
    {
        cout << "\n\n\tMAIN MENU";
        cout << "\n\n\t1.ADMINISTRATOR MODE";
        cout << "\n\n\t2.CUSTOMER MODE";
        cout << "\n\n\t3.EXIT THE PROGRAM";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
    }
    void AdminMenu()
    {
        cout << "\n\n\tADMIN MENU";
        cout << "\n\n\t1.CREATE PRODUCT";
        cout << "\n\n\t2.MODIFY PRODUCT";
        cout << "\n\n\t3.VIEW SPECIFIC PRODUCT";
        cout << "\n\n\t4.DISPLAY ALL PRODUCTS";
        cout << "\n\n\t5.DELETE PRODUCT";
        cout << "\n\n\t6.BACK TO MAIN MENU";
        cout << "\n\n\tPlease Enter Your Choice (1-6) ";
    }
};

#endif // MENU_H
