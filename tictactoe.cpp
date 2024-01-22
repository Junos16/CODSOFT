#include <iostream>
#include <vector>

void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));

    char currentPlayer = 'X';

    while (true) {
        displayBoard(board);

        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw(board)) {
                displayBoard(board);
                std::cout << "The game is a draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move. Try again.\n";
        }
    }

    char playAgain;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
        currentPlayer = 'X';
        main(); 
    }

    return 0;
}
