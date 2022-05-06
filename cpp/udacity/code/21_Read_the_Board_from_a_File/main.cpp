#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::vector;

#include <fstream>
using std::fstream;

// TODO: Add the ReadBoardFile function here.
void ReadBoardFile(string file_path) {
    fstream board_file(file_path);
    if (board_file) {
        string line;
        while (getline(board_file, line)) {
            cout << line << "\n";
        }
    } else {
        cout << "no such file " << file_path << "\n";
    }
}

// PrintBoard not used in this exercise
void PrintBoard(const vector<vector<int>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main() {
    // TODO: Call the ReadBoardFile function here.
    string file_path = "files/1.board";
    ReadBoardFile(file_path);
    // Leave the following line commented out.
    // PrintBoard(board);
}
