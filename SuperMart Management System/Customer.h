#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Product.h"

class Customer : public Product
{

protected:
    bool displaycheck;
    string product;
    int *Item, *Quantity, *rate;

public:
    Customer()
    {
        displaycheck = false;
        Item = new int[sIZE];
        Quantity = new int[sIZE];
        rate = new int[sIZE];
        product = "";

        for (int i = 0; i < sIZE; i++)
        {
            Item[i] = 0;
            Quantity[i] = 0;
            rate[i] = 0;
        }
    }
    bool CustomerMenu()
    {
        int i = 0, total = 0;
        char ch;
        bool ControlTransferToMainMenu = false; // When user dont want to do it again he will be diverted to Main Menu
        do
        {
            system("cls");
            ProgramInfo();
            cout << "\n\n\tCUSTOMER MENU\n\n";
            DisplayAllProducts();
            do
            {
                cout << "\n\tPlease Enter Serial Number to add Product in Cart : ";
                cin >> Item[i];
                product = ShowProduct(Item[i], displaycheck);
                while (product == "\0")
                {
                    cout << "\tEnter Again : ";
                    cin >> Item[i];
                    product = ShowProduct(Item[i], displaycheck);
                }
                string x, y, z;
                for (int j = 0, space = 0; product[j] != '\0'; j++)
                {
                    if (product[j] == ' ')
                    {
                        space++;
                    }
                    if (space >= 1 && space < 2)
                    {
                        z += product[j];
                    }
                    if (space >= 2 && space < 3)
                    {
                        x += product[j];
                    }
                    if (space >= 3 && space < 4)
                    {
                        y += product[j];
                    }
                }
                rate[i] = stoi(x);
                cout << "\tThe rate of " << z << " is " << rate[i];
                rate[i] = rate[i] - (rate[i] * (stof(y) / 100.0));
                cout << "\n\tDiscounted Rate : " << rate[i];

                cout << "\n\tEnter the quantity of this Item : ";
                cin >> Quantity[i];
                total += rate[i] * Quantity[i];
                i++;
                cout << "\n\tDo You Want To Order Another Product ? (y/n) : ";
                cin >> ch;
            } while (ch == 'y' || ch == 'Y');
            cout << "\n\n\t=========================================";
            cout << "\n\t\t\tTOTAL = " << total;
            cout << "\n\t=========================================";
            cout << "\n\n\t     Thank You For Placing The Order\n";

            cout << "\n\tDo You Want To Place Another Order ? (y/n) : ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        if (ch == 'n' || ch == 'N')
        {
            ControlTransferToMainMenu = true;
        }
        return ControlTransferToMainMenu;
    }
};
#endif
