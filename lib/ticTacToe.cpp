#include "ticTacToe.h"

#include <iostream>
#include <limits>
#include <string>

TicTacToe::TicTacToe() {
    for (int i = 0; i < 9; i++)
        board[i] = ' ';
}

void TicTacToe::playGame() {
    int noUsedSquares = 9;
    char playerTurn = 'X';
    char winner = ' ';
    int bestMove;

    _displayInitialBoard();

    while ((noUsedSquares > 0) && (winner == ' ')) {
        if (playerTurn == 'X') {
            _askPlayerX();
        } else {
            bestMove = _findBestMove();
            board[bestMove] = playerTurn;
        }

        _displayBoard();
        playerTurn = _otherPlayer(playerTurn);

        --noUsedSquares;
        winner = _winnerCheck();
    }

    if (winner == 'X')
        std::cout << "X won" << std::endl;
    else if (winner == 'O')
        std::cout << "O won" << std::endl;
    else
        std::cout << "Tie" << std::endl;
}

void TicTacToe::_displayInitialBoard() const {
    std::cout << "\nInstructions:"
              << "\nEnter 1 to 9 to make a move\n" << std::endl;

    for (int i = 0; i < 9; i += 3) {
        std::cout << "   " << i + 1 << " | " << i + 2 << " | " << i + 3 << std::endl;

        if (i < 6)
            std::cout << "  ---+---+---" << std::endl;
    }
    std::cout << std::endl;
}

void TicTacToe::_displayBoard() const {
    std::cout << std::endl;

    for (int i = 0; i < 9; i += 3) {
        std::cout << "   " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << std::endl;

        if (i < 6)
            std::cout << "  ---+---+---" << std::endl;
    }
    std::cout << std::endl;
}

void TicTacToe::_askPlayerX() {
    int square;
    bool validChoice = false;

    while (!validChoice) {
        std::cout << "Player X, enter a square number (1-9): ";

        if ((std::cin >> square) && (square >= 1) && (square <= 9) && (board[square - 1] == ' ')) {
            board[square - 1] = 'X';
            validChoice = true;
        } else {
            std::cerr << "Invalid choice. Try again.\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

char TicTacToe::_winnerCheck() const {
    // row and col
    for (int i = 0; i < 3; i++) {
        if (_compareSquares(board[i * 3], board[i * 3 + 1], board[i * 3 + 2]))
            return board[i * 3];
        if (_compareSquares(board[i], board[i + 3], board[i + 6]))
            return board[i];
    }
    // diag
    if (_compareSquares(board[0], board[4], board[8]))
        return board[0];
    if (_compareSquares(board[2], board[4], board[6]))
        return board[2];

    return ' ';
}

int TicTacToe::_evaluate() const {
    for (int i = 0; i < 3; ++i) {
        // row
        if (_compareSquares(board[i * 3], board[i * 3 + 1], board[i * 3 + 2]))
            return board[i * 3] == 'O' ? 10 : -10;
        // col
        if (_compareSquares(board[i], board[i + 3], board[i + 6]))
            return board[i] == 'O' ? 10 : -10;
    }

    // diag
    if (_compareSquares(board[0], board[4], board[8]) ||
        _compareSquares(board[2], board[4], board[6]))
        return board[4] == 'O' ? 10 : -10;

    return 0;
}

int TicTacToe::_minimax(int depth, bool isMax, int alpha, int beta) {
    int score = _evaluate();

    // traverse the tree
    std::string indent(depth * 2, ' ');
    if (depth == 0) std::cout << std::endl;
    std::cout << indent << "depth: " << depth 
              << (score == 10 ? "\tO won" : score == -10 ? "\tX won" : "") << std::endl;
    
    // base cases (win, lose, tie)
    if (score == 10) return score - depth;
    if (score == -10) return score + depth;
    if (!_movesLeft()) return 0;

    int best = isMax ? -1000 : 1000;
    char player = isMax ? 'O' : 'X';

    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = player;
            int val = _minimax(depth + 1, !isMax, alpha, beta);
            board[i] = ' ';

            if (isMax) {
                best = std::max(best, val);
                alpha = std::max(alpha, best);
            } else {
                best = std::min(best, val);
                beta = std::min(beta, best);
            }

            if (beta <= alpha)
                break;
        }
    }
    return best;
}

bool TicTacToe::_movesLeft() const {
    for (int i = 0; i < 9; i++)
        if (board[i] == ' ')
            return true;

    return false;
}

int TicTacToe::_findBestMove() {
    int bestVal = -1000;
    int bestMove = -1;

    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = 'O';
            int moveVal = _minimax(0, false, -1000, 1000);
            board[i] = ' ';

            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}
