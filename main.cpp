#include "learn.h"
#include "classify.h"


int main(int argc, char* argv[]) {
    if (argc == 8 || argc == 6) {
        std::string name_input_file;
        std::string name_output_file;
        if(strcmp(argv[1], "classify") == 0) {
            if (strcmp(argv[2], "--stats") == 0 && strcmp(argv[4], "--input") == 0 && strcmp(argv[6], "--output") == 0){
                std::string name_stat_file(argv[3]);
                read_statistic(name_stat_file);
                name_input_file = argv[5];
                prepare_classify(name_input_file);
                name_output_file = argv[7];
                write_result(name_output_file);
            } else {
                throw std::invalid_argument("invalud argiment");
            }
        } else if (strcmp(argv[1], "learn") == 0){
            if (strcmp(argv[2], "--input") == 0 && strcmp(argv[4], "--output") == 0){
                name_input_file = argv[3];
                uint32_t total_training_learn = 0;
                prepare_learn(name_input_file, total_training_learn);
                name_output_file = argv[5];
                write_statistic(name_output_file, total_training_learn);
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