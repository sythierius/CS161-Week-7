/***************************
 * Author: Charles Bennett
 * Date: 2/19/15
 * Description: This program will create a tictactoe game and play through the game with 2 players.
 * ***********************/
#include <iostream>
#include "Board.hpp"
#include "TicTacToe.hpp"

using namespace std;

// Default constructor
TicTacToe::TicTacToe()
{
  playerTurn='x';
}

// Overloaded constructor
TicTacToe::TicTacToe(char choice)
{
  playerTurn=choice;
}

/*******************************
 *     TicTacToe::play         *
 *Description: Starts a game   *
   of tictactoe, prompting user*
   for moves until game is     *
   completed.                  *
  parameters: none             *
*******************************/      
void TicTacToe::play()
{
  int outcome=3, // 3 means to keep playing
      selectionX,
      selectionY;
  bool flag=false; // flag is used to check if a valid move is made

  // Print initial empty board
  gameBoard.print(); 

  //  Loop forever if outcome is to keep playing
  while (outcome==3)
  {
    // Prompt user for move
    cout << "Player " << playerTurn << ", make your move." << endl;
    cout << "Type # for row, then a space, then # for column." << endl;
    cin >> selectionX >> selectionY; // input move
    flag=gameBoard.makeMove(selectionX, selectionY, playerTurn); // make move & set flag  
    // Print the board
    gameBoard.print();
    
    // If the move is invalid, ask for a new move
    while (flag==false)
    {
      cout << "Invalid move. That space is occupied." << endl;
      cout << "Player " << playerTurn << ", make a VALID move." << endl;
      cout << "Type # for row, then a space, then # for column." << endl; 
      cin >> selectionX >> selectionY;
      flag=gameBoard.makeMove(selectionX, selectionY, playerTurn);
      gameBoard.print();
    }
    
    // Check the outcome of the game
    outcome=gameBoard.gameState();
    
    // If x wins 
    if (outcome==0)
    {
      cout << "   CONGRATULATIONS, X!!!" << endl;
      cout << "You have defeated the evil O!" << endl;
      cout << endl;
      cout << "Final Gameboard:" << endl;
      gameBoard.print();
    }
    // If o wins
    if (outcome==1)
    {
      cout << "   CONGRATULATIONS, O!!!" << endl;
      cout << "You have defeated the evil X!" << endl;
      cout << endl; 
      cout << "Final Gameboard:" << endl;
      gameBoard.print();
    }
    // If cat's game
    if (outcome==2)
    {
      cout << "=^.^= Cat's game! =^.^=" << endl;
      cout << "   Tie! Nobody wins!" << endl;
      cout << endl;
      cout << "Final Gameboard:" << endl;
      gameBoard.print();
    }
    
    // Swap turns
    if (playerTurn=='x')
      playerTurn='o';
    else
      playerTurn='x';
  }
}

// *****************MAIN****************
int main()
{
  // Declare variables
  char turn;

  // Prompt for whose turn to start with
  cout << endl; 
  cout << "Welcome to TicTacToe!" << endl;
  cout << "Who will go first? x or o? "; 
  cin >> turn;
  cout << endl;
  cout << turn << " will go first! Let's get started!" << endl;
   
  // Create tictactoe object
  TicTacToe game(turn);
  game.play(); // Start the game

  return 0;
} 
