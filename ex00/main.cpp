#include "BitcoinExchange.hpp"

// parse_data()
// {
    
// }
// bool is_valid(std::string key)
// {
//     std::istringstream s(key);
//   std::tm t = {};
//   if (!(ss >> std::get_time(&t, "%Y-%m-%d"))) {
//     return false;
//   }
// }
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Failed to open." << filename << std::endl;
        return 1;
    }

    std::ifstream data;

    data.open("data.csv");
    if (!data.is_open()) {
    std::cerr << "Error: Failed to open." << std::endl;
    return 1;
    }
    // parse_data();
    std::string line;
    std::string key;
    std::string value;
    std::string datakey;
    std::string dataval;
    while (std::getline(file, line)) {
        // key = line.substr(0,line.find(" |"));
        // line.erase(0,line.find("| ") + 2);
        // value = line.substr(0,line.find('\n'));
        int pos = line.find('|');
        // if(pos == string::npos)
        //     std::cout << "error invalid input line" << std::endl;

        std::cout << "this key and value" << key << "-" << value << std::endl;
    }

    return 0;
}