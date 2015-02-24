/**************************
 * Author: Charles Bennett
 * Date: 2/19/15
 * Description: This class allows two people to play a tic tac toe game by greatting a board object and keeping track of whose turn it is.
 * ***********************/
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP
#include <iostream>
#include "Board.hpp"

using namespace std;

class TicTacToe
{
  private:
    Board gameBoard;
    char playerTurn;
  public:
    TicTacToe();
    TicTacToe(char);
    void play();
};
#endif 
