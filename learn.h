#include "base.h"


void prepare_learn(std::string& name_file);
inline void set_empty_input_learn(uint32_t& num_line, std::vector<std::string>& tags, std::string& title, std::string& text);
void get_tags(std::ifstream& file, std::string& line, std::vector<std::string>& tags);
void start_learn(std::vector<std::string>& tags, std::string& title, std::string& text);
void learn(std::string& text, std::string& cls);
void write_statistic(std::string& name_file);
