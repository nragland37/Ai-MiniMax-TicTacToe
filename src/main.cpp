#include "ticTacToe.h"

#include <iostream>

int main() {
    TicTacToe game;
    game.playGame();

    return 0;
}

//*****************************************************************************************************
/*
example output:

Player X, enter a square number (1-9): 6

   X | X | O
  ---+---+---
     | O | X
  ---+---+---
     |   |  


depth: 0
  depth: 1
    depth: 2
      depth: 3
    depth: 2
      depth: 3
  depth: 1
    depth: 2    O won
  depth: 1
    depth: 2    O won

depth: 0        O won

depth: 0
  depth: 1
    depth: 2    O won
    depth: 2
      depth: 3  X won
  depth: 1
    depth: 2
      depth: 3
    depth: 2
      depth: 3  X won
  depth: 1
    depth: 2
      depth: 3

depth: 0
  depth: 1
    depth: 2    O won
    depth: 2
      depth: 3  X won
  depth: 1
    depth: 2
      depth: 3
    depth: 2
      depth: 3  X won
  depth: 1
    depth: 2
      depth: 3

   X | X | O
  ---+---+---
     | O | X
  ---+---+---
   O |   |  

O won

*/