#include <iostream>
#include <stdexcept>

using namespace std;


int main(int argc, char* argv[]) {
    if (argc == 3) {
        if(strcmp(argv[1], "classify") == 0) {
            if (strcmp(argv[2], "--stats") == 0){
                cout << "--stats" << endl;
            } else if (strcmp(argv[2], "--input") == 0){
                cout << "--input" << endl;
            } else if (strcmp(argv[2], "--output") == 0){
                cout << "--output" << endl;
            } else {
                throw invalid_argument("invalud argiment");
            }
        } else if (strcmp(argv[1], "learn") == 0){
            if (strcmp(argv[2], "--input") == 0){
                cout << "--input" << endl;
            } else if (strcmp(argv[2], "--output") == 0){
                cout << "--output" << endl;
            } else {
                throw invalid_argument("invalud argiment");
            }
        } else {
            throw invalid_argument("invalud argiment");
        }
    } else {
        throw invalid_argument("invalud count argiments");
    }
    return 0;
}