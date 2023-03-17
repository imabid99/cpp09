#include "BitcoinExchange.hpp"

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return str.substr(first, last - first + 1);
}
bool StringDigit(std::string& str)
{
    std::string::iterator it = str.begin();
    std::string::iterator end = str.end();

    for (; it != end; ++it)
    {
        if (!std::isdigit(*it))
        {
            return false;
        }
    }
    return true;
}

int     check_date(int year, int month, int day)
{
    if(year < 2009 || year > 2022)
        std::cout << "Year " << year << " is invalid.\n";
    else if(month < 1 || month > 12)
         std::cout << "Month " << month << " is invalid.\n";
    else if(day < 1 || day > 31)
         std::cout << "Day " << day << " is invalid.\n";
    else if(month == 2 && day > 28)
         std::cout << "Month is " << month << " and day is " << day << " is invalid.\n";
    else if(month == 4 || month == 6 || month == 9 || month == 11 && day > 30)
        std::cout << "Month is " << month << " and day is " << day << " is invalid.\n";
    return 1;
}

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
    std::string firstLine;
    std::getline(file, firstLine);
    if (firstLine.substr(0, 6) == "date | value")
    {
        std::cout << "Error in first line : " << firstLine << "\n";
        std::getline(file, firstLine);
    }
    while (std::getline(file, line)) {
        // key = line.substr(0,line.find(" |"));
        // line.erase(0,line.find("| ") + 2);
        // value = line.substr(0,line.find('\n'));
        int pos = line.find('|');
        // if(pos == string::npos)
        //     std::cout << "error invalid input line" << std::endl;
        key = line.substr(0, pos);
        value = line.substr(pos + 1);
        key = trim(key);
        value = trim(value);
        if(key.size() != 10)
        {
            std::cerr << "Date error : " << value << std::endl;
            return 1;
        }
        std::stringstream ss(key);
        std::string year, month, day;
        int ryear, rmonth, rday;
        getline(ss, year, '-');
        getline(ss, month, '-');
        getline(ss, day);
        if(!StringDigit(year) || !StringDigit(month) || !StringDigit(day))
        {
            std::cout << "Error : You have error in date";
            return 1;
        }
        ryear = std::stoi(year);
        rmonth = std::stoi(month);
        rday = std::stoi(day);
        if(!check_date(ryear, rmonth, rday))
            return 0;
        std::cout << "Year: " << ryear << "\n";
        std::cout << "Month: " << rmonth << "\n";
        std::cout << "Day: " << rday << "\n";
        // std::string year, month, day;
        // std::cout << "this key and value |" << trim(key) << "|-|" << trim(value) << "|" << std::endl;
    }

    return 0;
}