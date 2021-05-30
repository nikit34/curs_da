#include "base.h"


void read_statistic(std::string& name_file);
void get_token(std::string& line, std::string& token);
void get_tokens_words(std::string& line, std::unordered_map<std::string, uint32_t>& words);
void set_empty_input_classify(uint32_t& num_line, std::string& title, std::string& text);
void prepare_classify(std::string& name_file);
void start_classify(std::string& title, std::string& text);
void classify(std::string& text, std::string& res);
void write_result(std::string& name_file);