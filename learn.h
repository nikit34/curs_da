#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>


struct class_statistic {
    uint32_t count_outdoor; // —колько раз этот класс встречалс€? (используетс€ дл€ приоритетов)
    uint32_t total_words; // —колько слов по€вилось дл€ этого класса?
    std::unordered_map<std::string, uint32_t> words; // —колько раз встречали каждое слово дл€ этого класса?
};

uint32_t total_trainings;
std::unordered_map<std::string, class_statistic> classes;

void prepare_learn(std::string& name_file);
inline void set_empty_input(uint32_t& num_line, std::vector<std::string>& tags, std::string& title, std::string& text);
inline void get_num_line(std::string& line, uint32_t& num_line);
void get_tags(std::ifstream& file, std::string& line, std::vector<std::string>& tags);
inline void get_title(std::ifstream& file, std::string& title);
void get_text(std::ifstream& file, std::string& line, uint32_t& num_line, std::string& text);
void start_learn(std::vector<std::string>& tags, std::string& title, std::string& text);
void learn(std::string& text, std::string& cls);
std::string& classify(std::string& text);