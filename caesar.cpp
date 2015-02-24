/********************************************
 * Author: Charles Bennett
 * Date: 2/17/15
 * Description: This program takes a cstring and a number to offset each character in the cstring, then offsets the characters and prints the new string.
 * *****************************************/
#include <iostream>
#include <string.h>

using namespace std;

// encipher prototype
void encipher(char msg[], int offset);

int main()
{
  // Declare variables
  char message[100];
  int off;

  // Ask user for input and assign to variables
  cout << "Please type a message and press enter." << endl;
  cin.getline(message,100, '\n');
  cout << "Please input the offset." << endl;
  cin >> off;
  
  // Call encipher function
  encipher(message, off);
  cout << endl;

  return 0;
}

/**********************************
 *         encipher               *
 * Description: This function is  *
 * used to offset each character  *
 * in a cstring by a certain      *
 * amount specified by the user   *
 * Parameters: char array, int    *
 * *******************************/
void encipher (char msg[], int offset)
{
  // Use for loop to individually print each character that is offset
  for (int i=0; i<strlen(msg); i++)
  {
    // Use temp variables so the values can be changed
    int tempMsg = msg[i];
    int tempOffset = offset;    

    // If the character is a number
    if (tempMsg>=48 && tempMsg<=57)
    {
      // Account for going out of number bounds
      while (tempMsg+tempOffset>57)
      {
        tempOffset-=10; // Adjust offset accordingly
      }
      while (tempMsg+tempOffset<48)
      {
        tempOffset+=10;
      }
      tempMsg+=tempOffset; // Add the offset to the ascii code
      cout << static_cast<char>(tempMsg); // Typecast char to the ascii code
    }

    // If the character is a capital
    if (tempMsg>=65 && tempMsg<=90)
    {
      while (tempMsg+tempOffset>90)
      {
        tempOffset-=26;
      }
      while (tempMsg+tempOffset<65)
      {
        tempOffset+=26;
      }
      tempMsg+=tempOffset;
      cout << static_cast<char>(tempMsg);
    }
  
    // If the character is a lowercase
    if (tempMsg>=97 && tempMsg<=122)
    {
      while (tempMsg+tempOffset>122)
      {
        tempOffset-=26;
      }
      while (tempMsg+tempOffset<97)
      {
        tempOffset+=26;
      }
      tempMsg+=tempOffset;
      cout << static_cast<char>(tempMsg);
    }

    // If the character is a symbol other than alphanumerical values
    if ((tempMsg>=0 && tempMsg<=47) || (tempMsg>=58 && tempMsg<=64) || (tempMsg>=91 && tempMsg<=96) || (tempMsg>=123))
    {
      cout << static_cast<char>(tempMsg); // DO NOT OFFSET and print value 
    }
  }
}     
         
          
