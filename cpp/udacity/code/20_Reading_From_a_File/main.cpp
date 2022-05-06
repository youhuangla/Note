#include <iostream>
#include <string>

// add this for file
#include <fstream>

void file_open_testing() {
    // initial a fstream object
    // std::fstream my_file;
    // my_file.open(path)

    // or initial in one line
    // std::ifstream my_file(path);
    std::fstream my_file;
    my_file.open("files/1.board");

    // this instance my_file can use as boolean to check is the file exist or not
    if (my_file) {
        std::cout << "we have this file"
                  << "\n";
    } else {
        std::cout << "we DON'T have this file"
                  << "\n";
    }
}

void reading_data_from_stream() {
    std::fstream my_file("files/1.board");
    if (my_file) {
        std::cout << "The file stream has been created!"
                  << "\n";
        std::string line;
        while (getline(my_file, line)) {
            std::cout << line << "\n";
        }
    }
}

/*
Four steps to reading a file:

1.#include <fstream>
2.Create a std::ifstream object using the path to your file.
3.Evaluate the std::ifstream object as a bool to ensure that the stream
    creation did not fail.
4.Use a while loop with getline to write file lines to a string.
*/

int main() {
    file_open_testing();
    reading_data_from_stream();
}
