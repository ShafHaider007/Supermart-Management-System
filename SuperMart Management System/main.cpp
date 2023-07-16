#include <iostream>
#include <windows.h>
#include <MMsystem.h>
// #include <mciapi.h>
#include "Product.h"
#include "Admin.h"
#include "Menu.h"
#include "Customer.h"
#include "MainScreen.h"

int main()
{
    MainScreen M;
    cout << Product::serialNumber << endl;
    M.Start();
}
