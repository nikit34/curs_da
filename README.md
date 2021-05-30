g++ -std=c++11 main.cpp learn.cpp classify.cpp base.cpp && ./a.out learn --input test.txt --output stat.txt

g++ -std=c++11 main.cpp learn.cpp classify.cpp base.cpp && ./a.out classify --stats stat.txt --input data.txt --output result.txt