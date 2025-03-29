/*
    Ruben Salazar
    CMPR 131
    March 23, 2025

    Homework 3

    Collaboration:
    None
*/

#include <iostream>
#include "ShoppingCart.h"
using namespace std;

int main()
{
    ShoppingCart cart1;
    char choice;

    while (choice != 'x')
    {
        cout << "1) Add item to your cart\n";
        cout << "2) Display your cart\n";
        cout << "3) Remove item from your cart\n";
        cout << "4) Clear your cart\n";
        cout << "5) Save cart\n";
        cout << "6) See the number of items in your cart\n";
        cout << "x) Exit\n";

        cout << "Choose an option: ";
        cin >> choice;

        string item;
        switch (choice)
        {
            case '1':
                cout << "What item do you want to add?: ";
                cin >> item;
                cout << endl;
                cart1.addItem(item);
                cout << endl;
                break;
            case '2':
                cout << endl;
                cout << cart1;
                cout << endl;
                break;
            case '3':
                cout << "What item do you want to remove?: ";
                cin >> item;
                cout << endl;
                cart1.removeItem(item);
                cout << endl;
                break;
            case '4':
                cout << endl;
                cart1.clearCart();
                cout << endl;
                break;
            case '5':
                cout << endl;
                cart1.saveCart();
                cout << endl;
                break;
            case '6':
                cout << endl;
                cout << "Number of items in cart: " << cart1.getNumOfItems() << endl << endl;
                break;
            case 'x':
                break;
            default:
                cout << endl;
                cout << "Invalid input!\n";
                break;
        }
    }

    return 0;
}
