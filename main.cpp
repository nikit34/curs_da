#include "learn.h"
#include "classify.h"


int main(int argc, char* argv[]) {
    if (argc == 8 || argc == 6) {
        std::string name_input_file;
        std::string name_output_file;
        if(strcmp(argv[1], "classify") == 0) {
            if (strcmp(argv[2], "--stats") == 0 && strcmp(argv[4], "--input") == 0 && strcmp(argv[6], "--output") == 0){
                std::string name_stat_file(argv[3]);
                name_input_file = argv[5];
                name_output_file = argv[7];

                uint32_t total_training_classify = 0;
                std::vector<std::string> result;
                std::unordered_map<std::string, class_statistic> classes_classify;

                read_statistic(name_stat_file, total_training_classify, classes_classify);
                prepare_classify(name_input_file, total_training_classify, result, classes_classify);
                write_result(name_output_file, result);
            } else {
                throw std::invalid_argument("invalud argiment");
            }
        } else if (strcmp(argv[1], "learn") == 0){
            if (strcmp(argv[2], "--input") == 0 && strcmp(argv[4], "--output") == 0){
                name_input_file = argv[3];
                name_output_file = argv[5];

                uint32_t total_training_learn = 0;
                std::unordered_map<std::string, class_statistic> classes_learn;

                prepare_learn(name_input_file, total_training_learn, classes_learn);
                write_statistic(name_output_file, total_training_learn, classes_learn);
            } else {
                throw std::invalid_argument("invalud argiment");
            }
        } else {
            throw std::invalid_argument("invalud argiment");
        }
    } else {
        throw std::invalid_argument("invalud count argiments");
    }
    return 0;
}