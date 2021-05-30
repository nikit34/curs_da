#include "learn.h"


int main(int argc, char* argv[]) {
    if (argc == 4 || argc == 6) {
        if(strcmp(argv[1], "classify") == 0) {
            if (strcmp(argv[2], "--stats") == 0){

            } else if (strcmp(argv[2], "--input") == 0){

            } else if (strcmp(argv[2], "--output") == 0){

            } else {
                throw std::invalid_argument("invalud argiment");
            }
        } else if (strcmp(argv[1], "learn") == 0){
            if (strcmp(argv[2], "--input") == 0 && strcmp(argv[4], "--output") == 0){
                std::string name_input_file(argv[3]);
                prepare_learn(name_input_file);
                std::string name_output_file(argv[5]);
                write_statistic(name_output_file);
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