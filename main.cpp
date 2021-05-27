#include <iostream>
#include <stdexcept>

using namespace std;


int main(int argc, char* argv[]) {
    if (argc == 4) {
        if(strcmp(argv[1], "classify")) {
            if (strcmp(argv[2], "--stats")){
                cout << "--stats" << endl;
            } else if (strcmp(argv[2], "--input")){
                cout << "--input" << endl;
            } else if (strcmp(argv[2], "--output")){
                cout << "--output" << endl;
            } else {
                invalid_argument("invalud argiment");
            }
        } else if (strcmp(argv[1], "learn")){
            if (strcmp(argv[2], "--input")){
                cout << "--input" << endl;
            } else if (strcmp(argv[2], "--output")){
                cout << "--output" << endl;
            } else {
                invalid_argument("invalud argiment");
            }
        } else {
            invalid_argument("invalud argiment");
        }
    } else {
        throw invalid_argument("invalud count argiments");
    }
    return 0;
}