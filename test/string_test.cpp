#include <iostream>

#include "../src/include/String.h"

using namespace std;
using namespace ea;

int main(int argc, char** argv)
{
    String str;
    String final_str;
    for (int i = 1; i < argc; ++i)
    {
        str = argv[i];
        std::cout << "length: " << str.length() << std::endl;
        std::cout << i << ":" << str << endl;
        final_str += str;
    }
    std::cout << final_str << std::endl;
    str = "";
    for(int i = 0; i < 100000; ++i) {
        str += "x";
    }
    std::cout << str << std::endl;
    return 0;
}
