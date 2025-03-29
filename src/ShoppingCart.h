/*
    Ruben Salazar
    CMPR 131
    March 23, 2025

    Homework 3

    Collaboration:
    None
*/

#pragma once
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <string>

struct Node
{
    std::string item;
    Node* next = nullptr;
};

class ShoppingCart
{
public:
    ShoppingCart();
    ShoppingCart(const ShoppingCart &otherCart);
    ~ShoppingCart();

    void addItem(std::string item);
    void removeItem(std::string item);
    void listItems() const;

    bool checkCase(std::string inCart, std::string removeItem);

    int getNumOfItems() const;

    void clearCart();

    void saveCart();

    friend std::ostream& operator<<(std::ostream& out, const ShoppingCart& myCart);

    ShoppingCart& operator=(const ShoppingCart& right);

private:
    Node* first;
    Node* last;
    int numOfItems;
};

#endif
