#include "docs_class.h"


void read_learn(std::string& name_file) {
    std::string line;
    std::ifstream file(name_file);

    uint32_t num_line;
    std::vector<std::string> tags;
    std::string title;
    std::string text = '';

    if (file.is_open()) {
        std::getline(file, line);
        num_line = std::stoi(line);

        std::getline(file, line);
        std::string s = ",";
        uint32_t pos = 0;
        std::string token;
        while ((pos = line.find(s)) != std::string::npos) {
            token = s.substr(0, pos);
            tags.push_back(token);
            line.erase(0, pos + 1);
        }
        tags.push_back(token);

        std::getline(file, title);

        while (num_line > 0) {
            std::getline(file, line);
            --num_line;
            text += line;
        }
        file.close();
    }
}