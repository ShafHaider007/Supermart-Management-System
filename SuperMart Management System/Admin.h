#ifndef ADMIN_H
#define ADMIN_H
#include"Customer.h"

class Admin :public Customer
{
public:
    void setProductDetails()
    {
        cout << "\n\n\tNOTE : DISCOUNT IS LIMITED UPTO 70%";
        cout << "\n\n\tEnter Unique ID of the Product :\t";
        cin >> ProductID;
        cout << "\n\tEnter name of the Product :\t";
        cin.ignore(1000, '\n');
        getline(cin, name);
        cout << "\n\tEnter Price of the Product :\t";
        cin >> price;
        cout << "\n\tEnter Discount for the Product (" << name << ") :\t";
        cin >> discount;
    }
    void AddProduct()
    {
        do
        {
            system("cls");
            ProgramInfo();
            setProductDetails();
        } while (ProductID < 1 || name == "\0" || price < 1 || discount < 0 || discount >70);
        WriteProduct();
    }
    void WriteProduct()
    {
        file.open("data.txt", ios::out | ios::app);
        file << this->ProductID << " " << this->name << " " << this->price << " " << this->discount << endl;
        file.close();
        cout << "\n\tThe Product has been added into the file " << endl;
    }
    void DeleteProduct()
    {
        int find;
        string line;
        string check;
        cout << "\n\tEnter the product Unique ID : ";
        cin >> find;
        ofstream file2;

        while ((ShowProduct(find, false)) == "\0")
        {
            cout << "\n\tPRODUCT DONOT EXIST, Enter Again :  ";
            cin >> find;
        }
        file.open("data.txt");
        file2.open("temp.txt");
        while (getline(file, line))
        {
            if (stoi(line) != find)
                file2 << line << endl;
        }
        file.close();
        file2.close();
        remove("data.txt");
        if (rename("temp.txt", "data.txt") != 0) {
            cout << "\nError in renaming File\n";
        }
    }
    void Modifyproduct()
    {
        DeleteProduct();
        AddProduct();
    }
};

#endif // !ADMIN_H
