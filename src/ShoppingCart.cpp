/*
    Ruben Salazar
    CMPR 131
    March 23, 2025

    Homework 3

    Collaboration:
    None
*/

#include "ShoppingCart.h"
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

// Constructor
ShoppingCart::ShoppingCart() : first(nullptr), last(nullptr), numOfItems(0) {}

// Destructor
ShoppingCart::~ShoppingCart()
{
    clearCart();
}

// Copy constructor
ShoppingCart::ShoppingCart(const ShoppingCart &otherCart)
{
    first = nullptr;
    last = nullptr;
    numOfItems = 0;

    Node* temp = otherCart.first;
    while (temp)
    {
        addItem(temp->item);
        temp = temp->next;
    }
}

// Adds item to the array
void ShoppingCart::addItem(string item)
{
    // Create node to carry the item we want to add
    Node* temp = new Node;
    temp->item = item;

    // If memory allocation fails, print an error message
    if (!temp)
    {
        cerr << "Allocation failed!\n";
    }
    else
    {
        // If we are adding the first node in the list
        if (!first)
        {
            first = temp;
            last = temp;
            numOfItems++;
            cout << "Succesfully added!\n";
        }
        // If we are adding beyond the first node
        else
        {
            last->next = temp;
            last = temp;
            numOfItems++;
            cout << "Succesfully added!\n";
        }
    }
}

// Removes an item by its name
void ShoppingCart::removeItem(string item)
{
    int noe = numOfItems;

    // Node to iterate starting at the beginning
    Node* current = first;

    // Node to keep track of the previous node in the iteration
    Node* prev = nullptr;

    int i = 0;
    while (current)
    {
        if (!checkCase(current->item, item))
        {
            cout << "Checking item " << ++i << "..." << endl;
        }
        // Check if the current node's item is equal to the item to remove
        else if (checkCase(current->item, item) || current->item == item)
        {
            // For the case that the item to be removed is the first item
            if (current == first)
            {
                first = current->next;
            }
            // Connect the previous node to the node that comes after the one to be removed
            else
            {
                prev->next = current->next;
            }

            // Delete the node and decrement the number of items
            delete current;
            numOfItems--;
            cout << "Successfully removed item " << ++i << endl;;
        }

        // Iterate through list
        prev = current;
        current = current->next;
    }

    if (noe == numOfItems)
    {
        cerr << "Failed to removed!\n";
    }
}

// Function that checks for case-sensitivity of the item in the cart and
// the item inputted by the user to remove
bool ShoppingCart::checkCase(string inCart, string removeItem)
{
    char* r_str = new char[removeItem.size()];

    char* c_str = new char[inCart.size()];

    for (int i = 0; i < removeItem.size(); i++)
    {
        r_str[i] = removeItem[i];
    }

    for (int i = 0; i < inCart.size(); i++)
    {
        c_str[i] = inCart[i];
    }

    int sameCount = 0;

    if (removeItem.size() > inCart.size())
    {
        return false;
    }
    // Checks if the first letter is lower case
    else if (islower(r_str[0]) || isupper(r_str[0]))
    {
        for (int i = 0; i < inCart.size(); i++)
        {
            int difference = r_str[i] - c_str[i];

            // Checks each letter and if the difference is 32 or -32, it means that r_str is lowercase
            // and c_str is uppercase or vice versa (a - A = 32) or (A - a = -32).
            // If the difference is 0 it means they are the same (a - a = 0) or (A - A = 0).
            if (difference == 32 || difference == -32  || difference == 0)
            {
                sameCount++;
            }
        }
    }

    // If the count on if the letters are the same is the same as the word, the words are the same
    if (sameCount == inCart.size())
    {
        return true;
    }

    delete[] r_str;
    delete[] c_str;
    r_str = nullptr;
    c_str = nullptr;

    return false;
}

// Prints the items onto the screen
void ShoppingCart::listItems() const
{
    Node* current = first;
    // Checks if the cart is empty
    if (numOfItems == 0)
    {
        cout << "Cart is empty." << endl;
    }
    else
    {
        for (int i = 0; i < numOfItems; i++)
        {
            cout << "Item " << i+1 << ": " << current->item << endl;
            current = current->next;
        }
    }
}

// Returns number of items
int ShoppingCart::getNumOfItems() const
{
    return numOfItems;
}

// Destroys the cart for the destructor to call
void ShoppingCart::clearCart()
{
    Node* current = first;
    while (current)
    {
        Node* temp = current->next;
        delete current;
        current = temp;
    }
    cout << "Succesfully cleared!\n";
    first = nullptr;
    last = nullptr;
    numOfItems = 0;
}

// Function that saves items in cart to a file
void ShoppingCart::saveCart()
{
    // Create an output stream
    ofstream file;
    file.open("Shopping Cart.txt"); // Name the text file

    // If the file is open, write to it
    if (file.is_open())
    {
        file << *this; // using the overloaded insertion operator and dereferencing the current object
        file.close();
        cout << "Successfully saved!" << endl;
    }
    else // Error checking if the file never opened
    {
        cerr << "Failed to write!" << endl;
    }
}

// Insertion operator overload
ostream& operator<<(ostream& out, const ShoppingCart& myCart)
{
    Node* current = myCart.first;

    // Check if the list has items to display
    if (myCart.numOfItems != 0)
    {
        for (int i = 0; i < myCart.numOfItems; i++)
        {
            out << "Item " << i+1 << ": " << current->item << endl;
            current = current->next;
        }
    }
    else
    {
        cout << "Cart is empty." << endl;
    }
    return out;
}

// Assignment operator overload
ShoppingCart& ShoppingCart::operator=(const ShoppingCart& right)
{
    if (this != &right)
    {
        clearCart();

        Node* temp = right.first;
        while (temp)
        {
            addItem(temp->item);
            temp = temp->next;
        }
    }
    return *this;
}
