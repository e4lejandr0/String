#include <iostream>
#include <fstream>

#include "../src/include/string.h"

#define SYNTAX_ERROR 1

class record 
{
public:
    ea::basic_string<char> property;
    std::vector<ea::basic_string<char>> values;
    bool is_valid;
};

record get_record(ea::basic_string<char>& line)
{
    record record_r{"", std::vector<ea::basic_string<char>>(), true};

    for(auto i = line.begin(); i != line.end(); ++i) {
        if(*i == '-') {
            line.crop(line.begin(), i);
        }
    }

    std::vector<ea::basic_string<char>> data = line.split('|');

    if(data.size() == 2) {
        record_r.property = data[0];
        for(ea::basic_string<char> value : data[1].split(',')) {
            value.trim();
            record_r.values.push_back(value);
        }
    } 
    else {
        std::cerr << "Syntax error in line(more separators than expected): " << std::endl;
        std::cerr << line << std::endl;
        record_r.is_valid = false;
    }
    return record_r;
}



int main(int argc, char** argv)
{
    std::ifstream config_file("test.cfg");
    ea::basic_string<char> line;
    std::vector<record> records;
    record current;
    
    do{
        current = get_record(line);
        records.push_back(current);
    } while (current.is_valid && config_file >> line);
    if(current.is_valid) {
        for(auto r : records) {
            std::cout << current.property << " = ["; 
            for(const ea::basic_string<char>& value : current.values) {
                std::cout << value;
                std::cout << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }
    else {
        return SYNTAX_ERROR;
    }

    return 0;
}
