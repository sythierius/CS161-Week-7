/*************************************
 * Author: Charles Bennett
 * Date: 2/19/15
 * Description: The board class creates a tictactoe game board and contains methods to make a move, check the state of the game, and print the board to the screen.
 * **********************************/
#include "Board.hpp"
#include <iostream>

using namespace std;
 
// Constructor
Board::Board()
{
  // Initialize board with '.' for all values
  for (int a=0; a<3; a++) // rows
  {
    for (int b=0; b<3; b++) // columns
    {
      grid[a][b]='.';
    }
  }
}

/*********************************
 *    Board::makeMove            *
 *Description: Checks if a move  *
   is possible, then makes the   *
   move and returns true or      * 
   false (if move isn't possible *
  Parameters: int, int, char     *
*********************************/    
bool Board::makeMove(int x, int y, char turn)
{
  // If move is possible, return true and make move
  if (grid[x][y]=='.')
  {
    grid[x][y]=turn;
    return true;
  }
  else // If move is not possible, don't make move and return false
    return false;
}

/*******************************
 *      Board::gameState       *
 *Description: Checks the state*
   of the game, if x wins,     *
   o wins, draw, or continue   *
  Parameter: none              *
*******************************/      
int Board::gameState()
{
  State result;
  // Top horizontal 
  if (grid[0][0]=='x'&&grid[0][1]=='x'&&grid[0][2]=='x')
  {
    result=X_Wins;
    return result;
  }
  // left vertical
  if (grid[0][0]=='x'&&grid[1][0]=='x'&&grid[2][0]=='x')
  {
    result=X_Wins;
    return result;
  }
  // down right diagonal
  if (grid[0][0]=='x'&&grid[1][1]=='x'&&grid[2][2]=='x')
  {
    result=X_Wins;
    return result;
  }
  // middle horizontal
  if (grid[1][0]=='x'&&grid[1][1]=='x'&&grid[1][2]=='x')
  {
    result=X_Wins;
    return result;
  }
  // bottom horizontal
  if (grid[2][0]=='x'&&grid[2][1]=='x'&&grid[2][2]=='x')
  {
    result=X_Wins;
    return result;
  }
  // down left diagonal 
  if (grid[0][2]=='x'&&grid[1][1]=='x'&&grid[2][0]=='x')
  {
    result=X_Wins;
    return result;
  }
  // middle vertical
  if (grid[0][1]=='x'&&grid[1][1]=='x'&&grid[2][1]=='x')
  {
    result=X_Wins;
    return result;
  }
  // right vertical
  if (grid[0][2]=='x'&&grid[1][2]=='x'&&grid[2][2]=='x')
  {
    result=X_Wins;
    return result;
  }
  
  // top horizontal
  if (grid[0][0]=='o'&&grid[0][1]=='o'&&grid[0][2]=='o')
  {
    result=O_Wins;
    return result;
  }
  // middle horizontal
  if (grid[1][0]=='o'&&grid[1][1]=='o'&&grid[1][2]=='o')
  {
    result=O_Wins;
    return result;
  }
  // bottom horizontal
  if (grid[2][0]=='o'&&grid[2][1]=='o'&&grid[2][2]=='o')
  {
    result=O_Wins;
    return result;
  }
  // left vertical
  if (grid[0][0]=='o'&&grid[1][0]=='o'&&grid[2][0]=='o')
  {
    result=O_Wins;
    return result;
  }
  // middle vertical
  if (grid[0][1]=='o'&&grid[1][1]=='o'&&grid[2][1]=='o')
  {
    result=O_Wins;
    return result;
  }
  // right vertical
  if (grid[0][2]=='o'&&grid[1][2]=='o'&&grid[2][2]=='o')
  {
    result=O_Wins;
    return result;
  }
  // down right diag
  if (grid[0][0]=='o'&&grid[1][1]=='o'&&grid[2][2]=='o')
  {
    result=O_Wins;
    return result;
  }
  // down left diag
  if (grid[0][2]=='o'&&grid[1][1]=='o'&&grid[2][0]=='o')
  {
    result=O_Wins;
    return result;
  }
  // If all spaces are occupied by x or o, then it is a draw
  if (grid[0][0]!='.'&&grid[0][1]!='.'&&grid[0][2]!='.'&&grid[1][0]!='.'&&grid[1][1]!='.'&&grid[1][2]!='.'&&grid[2][0]!='.'&&grid[2][1]!='.'&&grid[2][2]!='.')
  {
    result=Draw;
    return result;
  }
  else // if all other checks fail, keep playing
  {
    result=Keep_Playing;
    return result;
  }   
}

/**************************
 *    Board::print        *
 *Description: prints     (
   the game board to the  *
    screen                *
  Parameter: none         *
**************************/     
void Board::print()
{
  cout << endl;
  cout << "  0 1 2 " << endl; 
  
  // Loop through the array, printing each value
  for (int a=0; a<3; a++) // rows
  {
    cout << a << " "; 
    for (int b=0; b<3; b++) // columns
    {
      cout << grid[a][b] << " "; 
    }
    cout << endl;
  }

  cout << endl;
}  
