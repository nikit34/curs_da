#include "learn.h"


inline void set_empty_input(uint32_t& num_line, std::vector<std::string>& tags, std::string& title, std::string& text) {
    num_line = 0;
    tags.clear();
    title = "";
    text = "";
}

inline void get_num_line(std::string& line, uint32_t& num_line){
    num_line = std::stoi(line);
}

void get_tags(std::ifstream& file, std::string& line, std::vector<std::string>& tags){
    std::getline(file, line);
    std::string s = ",";
    int32_t pos = 0;
    std::string token;
    while ((pos = line.find(s)) != std::string::npos) {
        token = s.substr(0, pos);
        tags.push_back(token);
        line.erase(0, pos + 1);
    }
    tags.push_back(token);
}

inline void get_title(std::ifstream& file, std::string& title){
    std::getline(file, title);
}

void get_text(std::ifstream& file, std::string& line, uint32_t& num_line, std::string& text) {
    while (num_line > 0) {
        std::getline(file, line);
        --num_line;
        text += line;
    }
}

void prepare_learn(std::string& name_file){
    uint32_t num_line;
    std::vector<std::string> tags;
    std::string title;
    std::string text = "";

    std::string line;
    std::ifstream file(name_file);

    if (file.is_open()) {
        while(std::getline(file, line)){
            set_empty_input(num_line, tags, title, text);
            get_num_line(line, num_line);
            get_tags(file, line, tags);
            get_title(file, title);
            get_text(file, line, num_line, text);

            start_learn(tags, title, text);
        }
        file.close();
    }
}

void start_learn(std::vector<std::string>& tags, std::string& title, std::string& text){
    for (auto& tag : tags) {
        learn(title, tag);
        learn(text, tag);
    }
}

void learn(std::string& text, std::string& cls) {
    class_statistic cls_stat;
    ++total_trainings;

    if (classes.count(cls)) {
        cls_stat = classes[cls];
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

    classes[cls] = cls_stat;
}

std::string& classify(std::string& text) {
    std::unordered_map<std::string, uint32_t> word_counts;

    std::stringstream ss(text);
    std::string token;
    while (ss >> token) {
        ++word_counts[token];
    }

    double best = 0.0;
    std::string best_class = "";
    uint32_t laplace_smoothing;

    for (auto& cls : classes) {
        std::string name_class = cls.first;
        class_statistic cls_stat = cls.second;
        laplace_smoothing = cls_stat.total_words;

        for(auto& )
    }
}