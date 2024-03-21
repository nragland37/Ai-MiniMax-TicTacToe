#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
public:
    TicTacToe();
    void playGame();

private:
    char board[9];

    void _displayInitialBoard() const;
    void _displayBoard() const;
    void _askPlayerX();
    bool _compareSquares(char b1, char b2, char b3) const;
    char _winnerCheck() const;
    char _otherPlayer(char player) const;
    int _evaluate() const;
    int _minimax(int depth, bool isMax, int alpha, int beta);
    bool _movesLeft() const;
    int _findBestMove();
};

inline char TicTacToe::_otherPlayer(char player) const {
    return (player == 'X') ? 'O' : 'X';
}

inline bool TicTacToe::_compareSquares(char b1, char b2, char b3) const {
    return (b1 == b2) && (b2 == b3) && (b1 != ' ');
}

#endif