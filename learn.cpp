#include "learn.h"

uint32_t TOTAL_TRAINING = 0;
std::unordered_map<std::string, class_statistic> CLASSES;

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
        token = line.substr(0, pos);
        tags.push_back(token);
        line.erase(0, pos + 1);
    }
    tags.push_back(line);
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
    ++TOTAL_TRAINING;

    if (CLASSES.count(cls)) {
        cls_stat = CLASSES[cls];
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
    CLASSES[cls] = cls_stat;
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
    std::string name_class;
    class_statistic cls_stat;

    for (auto& cls : CLASSES) {
        name_class = cls.first;  // TODO: read from file
        cls_stat = cls.second;
        laplace_smoothing = cls_stat.total_words;

        for (auto& item_word_count : word_counts) {
            if (!cls_stat.words.count(item_word_count.first)) {
                ++laplace_smoothing;
            }
        }

        double metric_class = log(cls_stat.count_outdoor) - log(TOTAL_TRAINING);
        std::string word;
        uint32_t count;

        for (auto& item_word_count : word_counts) {
            word = item_word_count.first;
            count = item_word_count.second;

            if (cls_stat.words.count(word)) {
                metric_class += count * (log(cls_stat.words[word]) - log(laplace_smoothing));
            }
            else {
                metric_class += count * (-log(laplace_smoothing));
            }
        }

        if (best_class == "" || (metric_class > best)) {
            best = metric_class;
            best_class = name_class;
        }
    }
    return best_class;
}

void write_statistic(std::string& name_file) {
    std::ofstream file;
    file.open(name_file);
    file << TOTAL_TRAINING << std::endl;
    for (auto& cls : CLASSES) {
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

//void prepare_classify(std::string& name_file) {
//
//}