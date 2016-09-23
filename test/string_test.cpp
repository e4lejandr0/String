#include <iostream>
#include <fstream>

#include "../src/include/String.h"

#define SYNTAX_ERROR 1

class record 
{
public:
    ea::string property;
    std::vector<ea::string> values;
    bool is_valid;
};

record get_record(const ea::string& line, int line_number)
{
    record record_r{"", true};

    for(auto i = line.begin(); i != line.end(); ++i) {
        if(*i == '-') {
            line.crop(line.begin(), i);
        }
    }

    std::vector<ea::string> data = line.split('|');

    if(data.size() == 2) {
        record_r.property = data[0];
        for(ea::string value : data[1].split(",")) {
            value.trim();
            record_r.values.push_back(value);
        }
    } 
    else {
        std::cerr << "Syntax error in line(more separators than expected): " << std::endl;
        std::cerr << i << ":" << line;
        record_r.is_valid = false;
    }
    return record_r;
}



int main(int argc, char** argv)
{
    std::ifstream config_file("test.cfg");
    ea::string line;
    std::vector<record> records;
    record current;
    
    do{
        current = get_record(line);
        records.push_back(current);
    } while (current.is_valid && line << config_file);
    if(current.is_valid) {
        for(auto r : records) {
            std::cout << current.property << " = ["; 
            for(const ea::string& value : current.values) {
                std::cout << value;
                std::cout << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }
    else {
        return SYNTAX ERROR;
    }

    return 0;
}
