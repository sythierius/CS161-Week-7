/**********************************
 * Author: Charles Bennett
 * Date: 2/18/2015
 * Description: The item class is used to create item objects which include a string, double, and int value.
 * *******************************/
#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

using namespace std;

class Item
{
  private:
    string name;
    double price;
    int quantity;
  public:
    Item();
    Item(string,double,int);
    void setName(string);
    string getName();
    void setPrice(double);
    double getPrice();
    void setQuantity(int);
    int getQuantity();
};
#endif    
