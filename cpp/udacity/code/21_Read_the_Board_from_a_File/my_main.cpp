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
    fstream my_file(file_path);
    if (my_file) {
        cout << "The file stream has been created!" << "\n";
    }
    string line;
    while (getline(my_file, line)) {
        cout << line << "\n";
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
