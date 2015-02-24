/********************************************
 * Author: Charles Bennett
 * Date: 2/18/15
 * Description: The shoppingcart class creates a vector of Item objects, which are used to list the contents of all items in the vector and the price of the items, as well as the total price for all items.
 * *****************************************/
#ifndef SHOPCART_HPP
#define SHOPCART_HPP
#include <vector>
#include <iostream>
#include "Item.hpp"

using namespace std;

class ShoppingCart
{
  private:
    vector<Item> shopList;
  public:
    void addItem(Item);
    void listContents();
    double totalPrice();
};
#endif
