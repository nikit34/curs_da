#include "docs_class.h"


void read_learn(std::string& name_file) {
    std::string line;
    std::ifstream file(name_file);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::cout << line << '\n';
        }
        file.close();
    }
}