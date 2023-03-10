#include <iostream> // cout flush
#include <queue>
#include "lib/termcolor/termcolor.hpp"

void print(std::string type, std::string text) {
    std::cout << termcolor::reset;
    if (type == "response")
        std::cout << "> " << text << std::endl;
    else if (type == "info")
        std::cout << termcolor::red << "> " << text << termcolor::reset << std::endl;
    else if (type == "success")
        std::cout << termcolor::cyan << "> " << text << termcolor::reset << std::endl;
    else if (type == "great")
        std::cout << termcolor::green << "> " << text << termcolor::reset << std::endl; 
    else if (type == "warning")
        std::cout << termcolor::on_red << "  " << text << " " << termcolor::reset << std::endl;
    else if (type == "system")
        std::cout << text << std::endl;
}

std::queue<std::string> split(const std::string& s) {
    std::queue<std::string> out;

    std::string::size_type prev_pos = 0, pos = 0;

    while((pos = s.find(" ", pos)) != std::string::npos) {
        std::string substring(s.substr(prev_pos, pos-prev_pos));

        out.push(substring);
        
        prev_pos = ++pos;
    }

    out.push(s.substr(prev_pos, pos-prev_pos));

    return out;
}