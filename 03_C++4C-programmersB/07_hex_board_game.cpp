/*
    Hex board game

    Cristofer Costa
    cristofercosta@yahoo.com.br
*/

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Define player colors
enum class Player {
    Blue,
    Red
};
ostream& operator<<(ostream& out, const Player player){
    const string name[] = {"Red", "Blue"};
    out << name[static_cast<int>(player)];
    return out;
}


// Define cell states
enum class CellState {
    Empty,
    Blue,
    Red
};
ostream& operator<<(ostream& out, const CellState state){
    const string name[] = {"Empty", "Red", "Blue"};
    out << name[static_cast<int>(state)];
    return out;
}


// Define the HexBoard class
class HexBoard {
public:
    // Constructor initializes an empty board
    HexBoard(int boardSize):_bSize(boardSize){
        index = (_bSize -1) * _bSize + (_bSize - 1);
        // for (auto i = 0; i < n; i++)
        // {
        //     board[i / _bSize][i % _bSize] = CellState::Empty;
        // }
    };

    // Get board size
    getBoardSize(){
        std::string text;
        return text = index / _bSize
            + index % _bSize;
    };

    // Print the hex board
    void printBoard();

    // // Make a move on the board
    // bool makeMove(int row, int col, Player player);

    // // Check if the game is over
    // bool isGameOver();

    // // Get the winner of the game
    // Player getWinner();

private:
    int _bSize, index;
    std::vector<std::vector<CellState>> board;

    // // Check if a move is valid
    // bool isValidMove(int row, int col);

    // // Check if there is a path from start to end for the given player
    // bool hasPath(Player player, int startRow, int startCol, int endRow, int endCol, std::vector<std::vector<bool>>& visited);
};

// Print the hex board
// void HexBoard::printBoard() {
//     for (int i = 0; i < _bSize; ++i) {
//         for (int j = 0; j < i; ++j)
//             std::cout << " ";
//         for (int j = 0; j < _bSize; ++j) {
//             switch (board[i][j]) {
//                 case CellState::Empty:
//                     std::cout << ".";
//                     break;
//                 case CellState::Blue:
//                     std::cout << "B";
//                     break;
//                 case CellState::Red:
//                     std::cout << "R";
//                     break;
//             }
//             std::cout << " ";
//         }
//         std::cout << std::endl;
//     }
// }

int main() {
    
    /* code */
    HexBoard hexBoard(7);
    cout << "Board size: " << hexBoard.getBoardSize() << endl;
    // hexBoard.printBoard();
    Player currentPlayer = Player::Blue;
    cout << "Player: " << currentPlayer << endl;
    cout << "Hello world!";
    
    return 0;
}