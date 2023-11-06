#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

int main() {
    // Open the file for reading, conect a variable to a file for input
    std::ifstream data_file("data.txt");

    // Check if the file is open
    if (!data_file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    // pointing to the start and end of the file
    std::istream_iterator<int> start(data_file), end;

    // Vector constructor read from the start to the end of the file
    std::vector<int> data(start, end);

    for (double d : data) {
        std::cout << "Element: " << d <<  std::endl;
    }

    // Close the file when done
    data_file.close();

    return 0;
}
