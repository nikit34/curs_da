#include "base.h"


void get_num_line(std::string& line, uint32_t& num_line){
    num_line = std::stoi(line);
}

void get_title(std::ifstream& file, std::string& title){
    std::getline(file, title);
}

void get_text(std::ifstream& file, std::string& line, uint32_t& num_line, std::string& text) {
    while (num_line > 0) {
        std::getline(file, line);
        --num_line;
        text += line;
    }
}