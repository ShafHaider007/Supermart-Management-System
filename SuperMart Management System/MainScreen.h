#ifndef MAINSCREEN_H
// #define MAINSCREEN_H
#include "Menu.h"
#include <windows.h>

class MainScreen : public Admin, public Menu
{
private:
    int choice;

public:
    MainScreen() : choice(0) {}

    void login()
    {

        system("cls");
        static int tries = 3;
        if (tries == 0)
        {
            cout << "\n\n\tYou have No access to Admin Now (Diverting To Main Menu)\n\n";
            system("pause");
            Start();
        }
        string rusername, rpassword, username, password;
        cout << endl
             << "\n\n\t\t\tLOGIN PAGE " << endl;
        cout << "\n\n\tENTER USERNAME & PASSWORD BELOW (Tries = " << tries << ")" << endl;
        cout << "\n\tUSERNAME : ";
        cin >> username;
        cout << "\n\tPASSWORD : ";
        cin >> password;

        ifstream read("credentials.txt");
        read >> rusername >> rpassword;
        if (username == rusername && password == rpassword)
        {
            AdminOptions();
        }
        while (username != rusername || password != rpassword)
        {
            if (tries >= 0)
            {
                tries--;
                if (tries == 0)
                {
                    cout << "\n\tYou Entered Invalid Credentials .Please Contact Administrator\n\n\t" << endl;
                    system("pause");
                    Start();
                }
                login();
            }
        }
    }

    void Start()
    {
        do
        {
            system("cls");
            ProgramInfo();
            cout << "\n\n\tMAIN MENU";
            cout << "\n\n\t1.ADMINISTRATOR MODE";
            cout << "\n\n\t2.CUSTOMER MODE";
            cout << "\n\n\t3.EXIT THE PROGRAM";
            cout << "\n\n\tPlease Select Your Option (1-3) ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                login();
                // AdminOptions();
                break;
            case 2:
                if (CustomerMenu() == true)
                {
                    Start();
                }
                break;
            case 3:
                cout << "\n\t=> PROGRAM EXITED......\n\n";
                break;
            default:
                break;
            }
        } while (choice < 1 || choice > 3);
    }
    void IsValid()
    {
        char ch;
        cout << "\n\tPress 1 for Admin Menu, Press 0 for Main Menu: ";
        cin >> ch;
        if (ch == '1')
        {
            AdminOptions();
        }
        if (ch == '0')
        {
            Start();
        }
    }
    void AdminOptions()
    {
        do
        {
            system("cls");
            ProgramInfo();
            AdminMenu();
            cin >> choice;
            switch (choice)
            {
            case 1:
                AddProduct();
                IsValid();
                break;
            case 2:
                Modifyproduct();
                IsValid();
                break;
            case 3:
                cout << "\n\tEnter the Serial Number to get details : ";
                int check;
                cin >> check;
                if ((ShowProduct(check, true)) == "\0")
                {
                    cout << "\n\tPRODUCT DONOT EXIST" << endl;
                }
                IsValid();
                break;
            case 4:
                DisplayAllProducts();
                IsValid();
                break;
            case 5:
                DeleteProduct();
                IsValid();
                break;
            case 6:
                Start();
                break;
            default:
                break;
            }
        } while (choice < 1 || choice > 6);
    }
};

#endif
