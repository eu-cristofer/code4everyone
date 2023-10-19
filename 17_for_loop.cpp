#include <iostream>
#include <vector>

int main() {
    std::vector<int> data = {3, 2, 1};

    for (double d : data) {
        std::cout << "Element: " << d <<  std::endl;
    }

    return 0;
}