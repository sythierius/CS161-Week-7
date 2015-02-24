/****************************************
 * Author: Charles Bennett
 * Date: 2/19/15
 * Description: The board class creates a tictactoe board and allows a user to make a move on the board, and has a method to determine the result of the game 
 * *************************************/
#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>

using namespace std;

class Board
{
  private:
    char grid[3][3];
  public:
    Board();
    bool makeMove(int,int,char);
    int gameState();
    void print();
    enum State{X_Wins,O_Wins,Draw,Keep_Playing};
};
#endif      
