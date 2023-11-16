#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

std::vector<float> get_data(const std::string& file_name){
    // Open the text file for reading
    std::ifstream inputFile(file_name);
    
    if (!inputFile.is_open()) {
        std::cerr << "Could not open the datafile: " << file_name << std::endl;
        std::cerr << "Is that correct?" << std::endl;
        // Exit failure
        exit(1);
    }

    // Create a vector to store the float values
    std::vector<float> floatVector;
    
    std::string line;
    
    // Read the file line by line
    while (std::getline(inputFile, line)) {
        // Use a string stream to parse each line
        std::istringstream lineStream(line);
        float value;
        
        // Attempt to extract a float from the line
        while (lineStream >> value) {
            floatVector.push_back(value);
        }
    }
    
    // Close the file
    inputFile.close();
    return floatVector;
}

int main(int argc, char* argv[]) {
    // Check input data
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <yyyy-mm-dd>" << std::endl;
        return 1;
    }

    // Get the current date
    time_t current_time;
    struct tm* current_tm;
    time(&current_time);
    current_tm = localtime(&current_time);

    // Parse the input date
    struct tm input_tm;
    if (strptime(argv[1], "%Y-%m-%d", &input_tm) == nullptr) {
        std::cerr << "Invalid date format. Please use yyyy-mm-dd." << std::endl;
        return 1;
    }

    // Calculate the difference in months
    int months_diff = (current_tm->tm_year - input_tm.tm_year) * 12 +
                     (current_tm->tm_mon - input_tm.tm_mon);

    std::cout << "Difference in months: " << months_diff << std::endl;

    std::vector<float> data;

    data = get_data("wfa_girls_0-to-5-years_z0scores.txt");
    
    // Output the data from the vector
    for (float value : data) {
        std::cout << value << std::endl;
    }
    
    return 0;
}
