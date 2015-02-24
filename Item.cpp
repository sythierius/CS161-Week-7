/*********************************
 * Author: Charles Bennett
 * Date: 2/18/15
 * Description: This class is used to create Item objects which contain a string value, a double value, and an int value, representing name, price, and quantity.
 * *******************************/
#include "Item.hpp"
#include <string>

using namespace std;

// Default constructor
Item::Item()
{
  setName("");
  setPrice(0.0);
  setQuantity(0);
}

// Overloaded constructor
Item::Item(string nam, double pri, int qty)
{
  setName(nam);
  setPrice(pri);
  setQuantity(qty);
}

// Item::setName
void Item::setName(string nam)
{
  name = nam;
}

// Item::getName
string Item::getName()
{
  return name;
}

// Item::setPrice
void Item::setPrice(double pri)
{
  price = pri;
}

// Item::getPrice
double Item::getPrice()
{
  return price;
}

// Item::setQuantity
void Item::setQuantity(int qty)
{
  quantity=qty;
}

// Item::getQuantity
int Item::getQuantity()
{
  return quantity;
}

