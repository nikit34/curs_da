#include "base.h"


void prepare_learn(std::string& name_file, uint32_t& total_training_learn, std::unordered_map<std::string, class_statistic>& classes_learn);
inline void set_empty_input_learn(uint32_t& num_line, std::vector<std::string>& tags, std::string& title, std::string& text);
void get_tags(std::ifstream& file, std::string& line, std::vector<std::string>& tags);
void start_learn(std::vector<std::string>& tags, std::string& title, std::string& text, uint32_t& total_training_learn, std::unordered_map<std::string, class_statistic>& classes_learn);
void learn(std::string& text, std::string& cls, uint32_t& total_training_learn, std::unordered_map<std::string, class_statistic>& classes_learn);
void write_statistic(std::string& name_file, uint32_t& total_training_learn, std::unordered_map<std::string, class_statistic>& classes_learn);
