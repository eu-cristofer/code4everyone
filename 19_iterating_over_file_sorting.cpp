#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>

int main() {
    // Open the file for reading, conect a variable to a file for input
    std::ifstream data_file("words.txt");

    // Check if the file is open
    if (!data_file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    // pointing to the start and end of the file
    std::istream_iterator<std::string> start(data_file), end;

    // Vector constructor read from the start to the end of the file
    std::vector<std::string> words(start, end);

    // Sorting
    std::sort(words.begin(), words.end());

    // Printing it
    for (auto word : words) {
        std::cout << "Element: " << word <<  std::endl;
    }

    // Close the file when done
    data_file.close();

    return 0;
}
