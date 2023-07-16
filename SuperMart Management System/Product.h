#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;
fstream file;
const int sIZE = 100;

class Product
{
protected:
    string name;
    int ProductID, quantity;
    float price, discount;

public:

    static int serialNumber;
    void ProgramInfo()
    {

        cout << "\t\t  #####    #     #   ######  ######   #####       ##       ##       #      #####     #   #    #####   ####### " << endl;
        cout << "\t\t #         #     #   #    #  #        #    #      # #     # #      # #     #    #    #  #     #          #    " << endl;
        cout << "\t\t  #####    #     #   # ###   ######   #####       #  #   #  #     #####    #####     ##       #####      #    " << endl;
        cout << "\t\t       #   #     #   #       #        #   #       #   # #   #    #     #   #   #     #  #     #          #    " << endl;
        cout << "\t\t  #####    #######   #       ######   #    #      #    #    #   #       #  #    #    #   #    #####      #    " << endl << endl << endl;


        cout << "  #         #     #     #      #     #      ####   ##### #         # ##### #      # #######          #####   #   #   #####  ####### ###### #         #  " << endl;
        cout << "  # #     # #    # #    # #    #    # #    #       #     # #     # # #     # #    #    #            #     #   # #   #     #    #    #      # #     # #  " << endl;
        cout << "  #  #   #  #   #####   #  #   #   #####   #  ###  ###   #  #   #  # ####  #  #   #    #             ###       #     ###       #    #####  #  #   #  #  " << endl;
        cout << "  #   # #   #  #     #  #   #  #  #     #  #    #  #     #   # #   # #     #   #  #    #          #     #      #  #     #      #    #      #   # #   #  " << endl;
        cout << "  #    #    # #       # #    # # #       #  #####  ##### #    #    # ##### #    # #    #           #####       #   #####       #    ###### #    #    #  " << endl;
        cout << "________________________________________________________________________________________________________________________________________________________" << endl;
        cout << "________________________________________________________________________________________________________________________________________________________\n" << endl;

    }


    Product()
    {
        name = "";
        ProductID = 0;
        quantity = 0;
        price = 0.0;
        discount = 0.0;
    }
    Product(int id, string n, float pr, float ds, int qty)
    {
        name = "";
        ProductID = id;
        quantity = qty;
        price = pr;
        discount = ds;
    }
    void DisplayAllProducts()
    {
        system("cls");
        ProgramInfo();
        cout << "\n\n\n\tPRODUCTS LIST\n\n";
        file.open("data.txt", ios::in);
        if (!file)
        {
            cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File ";
            cout << "\n\n\n Program is closing ....";
            exit(0);
        }
        string text;
        Format();
        cout << endl;
        while (!file.eof())
        {
            getline(file, text);
            {
                DisplayFormat(text);
            }
        }
        file.close();
    }

    string ShowProduct(int item, bool flag)
    {
        file.open("data.txt", ios::in);
        if (!file)
        {
            cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File ";
            cout << "\n\n\n Program is closing ....";
            exit(0);
        }
        string text;
        while (!file.eof())
        {
            getline(file, text);

            if (!file.eof())
            {
                //this line will convert string into integer and check that serial number is matching with file string or not
                //stoi function change string to integer
                if (item == stoi(text))
                {
                    if (flag == true)
                    {
                        Format();
                        DisplayFormat(text);
                    }
                    break;
                }
            }
            else
            {
                if (!file.eof())
                    continue;
            }
        }
        file.close();
        return text;
    }


    int getSerialNo()
    {
        return ProductID;
    }
    float getPrice()
    {
        return price;
    }
    string getName()
    {
        return name;
    }
    float getDiscount()
    {
        return discount;
    }
    void Format()
    {
        cout << setw(10) << "S.No" << setw(15) << right << "Product Name" << setw(15) << "Price" << setw(16) << "Discount(%)\n";
    }
    void DisplayFormat(string x)
    {
        string a, b, c, d;
        for (int j = 0, space = 0; x[j] != '\0'; j++)
        {
            if (x[j] == ' ')
            {
                space++;
            }
            if (space >= 0 && space < 1)
            {
                a += x[j];
            }
            if (space >= 1 && space < 2)
            {
                b += x[j];
            }
            if (space >= 2 && space < 3)
            {
                c += x[j];
            }
            if (space >= 3 && x[j] != '\0')
            {
                d += x[j];
            }
        }
        cout << setw(10) << a << setw(20) << left << b << setw(10) << right << c << setw(10) << right << d << endl;
    }
};
int Product::serialNumber = 0;

#endif // !PRODUCT_H

