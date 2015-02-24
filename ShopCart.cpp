/**************************************
 * Author: Charles Bennett
 * Date: 2/18/15
 * Description: This class utilizes a vector of Item objects to create a shopping list, and contains functions to add more items, list the contents of the list, and total the price of all items on the list.
 * ***********************************/
#include "ShopCart.hpp"
#include "Item.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std; 

/**************************************
 *        ShoppingCart::addItem       *
 *Description: This adds an item obj  *
   to the end of the shopList vector  *
  Parameter: Item object              *
**************************************/       
void ShoppingCart::addItem(Item newItem)
{
  shopList.push_back(newItem);
}

/****************************************
 *     ShoppingCart::listContents       *
 *Description: This prints the contents *
   of the shopList vector to the screen * 
  Parameter: none                       *
****************************************/
void ShoppingCart::listContents()
{
  cout << endl;
  cout << "Here are the contents of your cart:" << endl;

  //  Loop to display contents of each item object in the vector individually
  for (int i=0; i<shopList.size(); i++)
  {
    cout << fixed << setprecision(2);
    cout << "Item #" << i+1 << ":" << endl;
    cout << "Name: " << shopList[i].getName() << endl;
    cout << "Price: $" << shopList[i].getPrice() << endl;
    cout << "Quantity: " << shopList[i].getQuantity() << endl;
    cout << endl;
  }
}

/****************************************
 *   ShoppingCart::totalPrice           *
 *Description: This adds all values     *
   for price in each Item object in the *
   shopList vector and returns the total*
  Parameter: none                       *
****************************************/   
double ShoppingCart::totalPrice()
{
  double total=0;

  for (int i=0; i<shopList.size(); i++)
  {
    total+=(shopList[i].getPrice()*shopList[i].getQuantity());
  }
  
  return total;
}

// **************MAIN*****************
int main()
{
  // declare variables
  string nam;
  double pri,
         intCheck; // Used for input validation  
  int qty,
      selection;
  bool valid=false; // Used for input validation
  Item product; // Empty item object for adding items
  ShoppingCart cart; // Empty cart object for items to be added to

  // do/while loop to create menu
  do
  {
    // Menu options
    cout << endl;
    cout << "Please select one of the following options:" << endl;
    cout << "1. Add Item to Cart" << endl;
    cout << "2. List Contents of Cart" << endl;
    cout << "3. Find Total Price of All Items in Cart" << endl; 
    cout << "4. Quit" << endl;
    cout << endl;
    cin >> selection;
     
    // Switch/case to execute selection
    switch(selection)
    {
      // Add a new item
      case 1:
        cout << "Please input the name of the item." << endl;
        cin >> nam;
        product.setName(nam); // sets name to temporary item object
  
        do 
        {
          cout << "Please input the price of the item." << endl;
          cin >> pri;
          // Input validation
          if (cin.fail()==0)
            valid=true;
          else
          {
            valid=false; 
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid value for price. Please re-enter." << endl;
          }
        } while(!valid);
        product.setPrice(pri); // sets price to temporary item object

        do 
        {
          cout << "Please input the quantity of the item." << endl;
          cin >> intCheck;

          // input validation  
          qty=intCheck;
          if (cin.fail()==0 && intCheck==qty) // checks if the double value is equal to the int
            valid=true;
          else
          {
            valid=false;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid quantity. Please re-enter." << endl;
          }
        } while (!valid);
        product.setQuantity(qty); // sets quantity to temporary item object          
        
        // Adds the temporary item object to the vector in the ShoppingCart object 
        cart.addItem(product); 
        break;
     
      // List cart contents
      case 2:
        cart.listContents();
        break;
     
      // Print total price of items in cart 
      case 3:
        cout << fixed << setprecision(2) << endl;
        cout << "The total price of all items is $" << cart.totalPrice() << endl; 
        break;

      // Exit the menu
      case 4:
        cout << "Goodbye!" << endl;
        break;  
    } 
  } while (selection!=4);

  return 0;
}
    
