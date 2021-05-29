#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <vector>


void prepare_learn(std::string& name_file);
inline void set_empty_input(uint32_t& num_line, std::vector<std::string>& tags, std::string& title, std::string& text);
inline void get_num_line(std::string& line, uint32_t& num_line);
void get_tags(std::ifstream& file, std::string& line, std::vector<std::string>& tags);
inline void get_title(std::ifstream& file, std::string& title);
void get_text(std::ifstream& file, std::string& line, uint32_t& num_line, std::string& text);