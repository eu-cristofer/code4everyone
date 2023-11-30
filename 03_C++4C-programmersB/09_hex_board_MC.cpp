/*
    Hex board game with Monte Carlo simulation

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>
#include <vector>
#include <limits>

// Define player colors
enum class Player {
    Blue,
    Red
};

// Define cell states
enum class CellState {
    Empty,
    Blue,
    Red
};

// Define the HexBoard class
class HexBoard {
public:
    // Constructor initializes an empty board
    HexBoard();

    // Print the hex board
    void printBoard();

    // Make a move on the board
    bool makeMove(int row, int col, Player player);

    // Check if the game is over
    bool isGameOver();

    // Get the winner of the game
    Player getWinner();

    // Monte Carlo simulation to estimate winning probabilities
    std::pair<double, double> monteCarloSimulation(int numSimulations);

private:
    const int boardSize = 7;
    std::vector<std::vector<CellState>> board;

    // Check if a move is valid
    bool isValidMove(int row, int col);

    // Check if there is a path from start to end for the given player
    bool hasPath(Player player, int startRow, int startCol, int endRow, int endCol, std::vector<std::vector<bool>>& visited);

    // Helper function for Monte Carlo simulation
    Player simulateRandomGame();
};

// Constructor initializes an empty board
HexBoard::HexBoard() : board(boardSize, std::vector<CellState>(boardSize, CellState::Empty)) {}

// Print the hex board
void HexBoard::printBoard() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < i; ++j)
            std::cout << " ";
        for (int j = 0; j < boardSize; ++j) {
            switch (board[i][j]) {
                case CellState::Empty:
                    std::cout << ".";
                    break;
                case CellState::Blue:
                    std::cout << "B";
                    break;
                case CellState::Red:
                    std::cout << "R";
                    break;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

// Check if a move is valid
bool HexBoard::isValidMove(int row, int col) {
    return row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] == CellState::Empty;
}

// Make a move on the board
bool HexBoard::makeMove(int row, int col, Player player) {
    if (isValidMove(row, col)) {
        board[row][col] = (player == Player::Blue) ? CellState::Blue : CellState::Red;
        return true;
    } else {
        std::cout << "Invalid move. Try again." << std::endl;
        return false;
    }
}

// Check if the game is over
bool HexBoard::isGameOver() {
    for (int i = 0; i < boardSize; ++i) {
        if (board[0][i] == CellState::Blue && hasPath(Player::Blue, 0, i, boardSize - 1, i, std::vector<std::vector<bool>>(boardSize, std::vector<bool>(boardSize, false))))
            return true;
        if (board[i][0] == CellState::Red && hasPath(Player::Red, i, 0, i, boardSize - 1, std::vector<std::vector<bool>>(boardSize, std::vector<bool>(boardSize, false))))
            return true;
    }
    return false;
}

// Check if there is a path from start to end for the given player
bool HexBoard::hasPath(Player player, int startRow, int startCol, int endRow, int endCol, std::vector<std::vector<bool>>& visited) {
    if (startRow == endRow && startCol == endCol)
        return true;

    visited[startRow][startCol] = true;

    int deltaRow[] = {-1, -1, 0, 0, 1, 1};
    int deltaCol[] = {-1, 0, -1, 1, 0, 1};

    for (int i = 0; i < 6; ++i) {
        int newRow = startRow + deltaRow[i];
        int newCol = startCol + deltaCol[i];

        if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize &&
            board[newRow][newCol] == static_cast<CellState>(player) && !visited[newRow][newCol]) {
            if (hasPath(player, newRow, newCol, endRow, endCol, visited))
                return true;
        }
    }

    return false;
}

// Get the winner of the game
Player HexBoard::getWinner() {
    return isGameOver() ? Player::Blue : Player::Red;
}

// Monte Carlo simulation to estimate winning probabilities
std::pair<double, double> HexBoard::monteCarloSimulation(int numSimulations) {
    int blueWins = 0;
    int redWins = 0;

    for (int i = 0; i < numSimulations; ++i) {
        Player winner = simulateRandomGame();
        if (winner == Player::Blue) {
            blueWins++;
        } else {
            redWins++;
        }
    }

    double blueWinPercentage = static_cast<double>(blueWins) / numSimulations * 100.0;
    double redWinPercentage = static_cast<double>(redWins) / numSimulations * 100.0;

    return {blueWinPercentage, redWinPercentage};
}

// Helper function for Monte Carlo simulation
Player HexBoard::simulateRandomGame() {
    HexBoard tempBoard = *this;  // Create a copy of the current board
    Player currentPlayer = Player::Blue;

    while (!tempBoard.isGameOver()) {
        // Simulate a random move
        int row, col;
        do {
            row = rand() % boardSize;
            col = rand() % boardSize;
        } while (!tempBoard.isValidMove(row, col));

        tempBoard.makeMove(row, col, currentPlayer);

        currentPlayer = (currentPlayer == Player::Blue) ? Player::Red : Player::Blue;
    }

    return tempBoard.getWinner();
}

int main() {
    HexBoard hexBoard;
    Player currentPlayer = Player::Blue;

    while (!hexBoard.isGameOver()) {
        hexBoard.printBoard();

        int row, col;
        std::cout << "Enter your move (row and column): ";
        std::cin >> row >> col;

        while (!hexBoard.makeMove(row, col, currentPlayer)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid move. Try again: ";
            std::cin >> row >> col;
        }

        currentPlayer = (currentPlayer == Player::Blue) ? Player::Red : Player::Blue;
    }

    hexBoard.printBoard();
    std::cout << "Player " << static_cast<int>(hexBoard.getWinner()) + 1 << " wins!" << std::endl;

    return 0;
}
