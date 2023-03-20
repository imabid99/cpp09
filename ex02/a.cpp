#include <iostream>
#include <cstring>
#include <cctype>

bool is_positive_number(const std::string& str) {
    // Check if the string is a positive number
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    // Check if there are at least two arguments
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <positive integer> [positive integer] ..." << std::endl;
        return 1;
    }

    // Initialize the sum to zero
    int sum = 0;

    // Loop through the arguments and add the positive integers to the sum
    for (int i = 1; i < argc; i++) {
        // Check if the argument is a positive number
        std::string arg = argv[i];
        if (!is_positive_number(arg)) {
            std::cout << "Error: All arguments must be positive integers." << std::endl;
            return 1;
        }

        // Convert the argument to an integer
        int number = std::stoi(arg);

        // Check if the number is positive
        if (number <= 0) {
            std::cout << "Error: All arguments must be positive integers." << std::endl;
            return 1;
        }

        sum += number;
    }

    // Print the sum
    std::cout << "The sum is: " << sum << std::endl;

    return 0;
}