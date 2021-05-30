#include "classify.h"


uint32_t TOTAL_TRAINING_CLASSIFY = 0;
std::unordered_map<std::string, class_statistic> CLASSES_CLASSIFY;

void read_statistic(std::string& name_file){
    std::ifstream file;
    file.open(name_file);
    std::string line;

    file >> TOTAL_TRAINING_CLASSIFY;

    std::string tag;
    std::string tmp;

    while (std::getline(file, line)) {
        class_statistic cls_stat;
        get_token(line, tag);


        get_token(line, tmp);
        cls_stat.count_outdoor = atoi(tmp.c_str());
        get_token(line, tmp);
        cls_stat.total_words = atoi(tmp.c_str());
        get_tokens_words(line, cls_stat.words);
        CLASSES_CLASSIFY[tag] = cls_stat;
    }
    file.close();
}

void get_token(std::string& line, std::string& token){
    std::string s = ",";
    int32_t pos = 0;
    if ((pos = line.find(s)) != std::string::npos) {
        token = line.substr(0, pos);
        line.erase(0, pos + 1);
    }
}

void get_tokens_words(std::string& line, std::unordered_map<std::string, uint32_t>& words){
    std::string s_comma = ",";
    std::string s_colon = ":";
    int32_t pos_token = 0;
    int32_t pos_word;
    std::string token;
    std::string word;
    uint32_t count;
    while ((pos_token = line.find(s_comma)) != std::string::npos) {
        token = line.substr(0, pos_token);

        pos_word = token.find(s_colon);
        word = token.substr(0, pos_word);
        count = atoi(token.substr(pos_word + 1, pos_token).c_str());

        line.erase(0, pos_token + 1);
        words[word] = count;
    }
}

void set_empty_input_classify(uint32_t& num_line, std::string& title, std::string& text){
    num_line = 0;
    title = "";
    text = "";
}

void prepare_classify(std::string& name_file) {
    uint32_t num_line;
    std::string title;
    std::string text = "";

    std::string line;
    std::ifstream file(name_file);
    if (file.is_open()) {
        while(std::getline(file, line)){
            set_empty_input_classify(num_line, title, text);
            get_num_line(line, num_line);
            get_title(file, title);
            get_text(file, line, num_line, text);

            start_classify(title, text);
        }
        file.close();
    }
}

void start_classify(std::string& title, std::string& text){
    classify(title);
    classify(text);
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

    for (auto& cls : CLASSES_CLASSIFY) {
        name_class = cls.first;  // TODO: read from file
        cls_stat = cls.second;
        laplace_smoothing = cls_stat.total_words;

        for (auto& item_word_count : word_counts) {
            if (!cls_stat.words.count(item_word_count.first)) {
                ++laplace_smoothing;
            }
        }

        double metric_class = log(cls_stat.count_outdoor) - log(TOTAL_TRAINING_CLASSIFY);
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
    std::cout << best_class;
    return best_class;
}