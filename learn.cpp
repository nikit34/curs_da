#include "learn.h"


inline void set_empty_input_learn(uint32_t& num_line, std::vector<std::string>& tags, std::string& title, std::string& text) {
    num_line = 0;
    tags.clear();
    title = "";
    text = "";
}

void get_tags(std::ifstream& file, std::string& line, std::vector<std::string>& tags){
    std::getline(file, line);
    std::string s = ",";
    int32_t pos = 0;
    std::string token;
    while ((pos = line.find(s)) != std::string::npos) {
        token = line.substr(0, pos);
        tags.push_back(token);
        line.erase(0, pos + 1);
    }
    tags.push_back(line);
}

void prepare_learn(std::string& name_file, uint32_t& total_training_learn, std::unordered_map<std::string, class_statistic>& classes_learn){
    uint32_t num_line;
    std::vector<std::string> tags;
    std::string title;
    std::string text = "";

    std::string line;
    std::ifstream file(name_file);

    if (file.is_open()) {
        while(std::getline(file, line)){
            set_empty_input_learn(num_line, tags, title, text);
            get_num_line(line, num_line);
            get_tags(file, line, tags);
            get_title(file, title);
            get_text(file, line, num_line, text);

            start_learn(tags, title, text, total_training_learn, classes_learn);
        }
        file.close();
    }
}

void start_learn(std::vector<std::string>& tags, std::string& title, std::string& text, uint32_t& total_training_learn, std::unordered_map<std::string, class_statistic>& classes_learn){
    for (auto& tag : tags) {
        learn(title, tag, total_training_learn, classes_learn);
        learn(text, tag, total_training_learn, classes_learn);
    }
}

void learn(std::string& text, std::string& cls, uint32_t& total_training_learn, std::unordered_map<std::string, class_statistic>& classes_learn) {
    class_statistic cls_stat;
    ++total_training_learn;

    if (classes_learn.count(cls)) {
        cls_stat = classes_learn[cls];
    }
    else {
        cls_stat.count_outdoor = 0;
        cls_stat.words.clear();
    }

    ++cls_stat.count_outdoor;

    std::stringstream ss(text);
    std::string token;
    while (ss >> token) {
        ++cls_stat.words[token];
        ++cls_stat.total_words;
    }
    classes_learn[cls] = cls_stat;
}

void write_statistic(std::string& name_file, uint32_t& total_training_learn, std::unordered_map<std::string, class_statistic>& classes_learn) {
    std::ofstream file;
    file.open(name_file);
    file << total_training_learn << std::endl;
    for (auto& cls : classes_learn) {
        file << cls.first;
        file << "," << cls.second.count_outdoor;
        file << "," << cls.second.total_words;
        for (auto& token : cls.second.words){
            file << "," << token.first << ":" << token.second;
        }
        file << std::endl;
    }
    file.close();
}
