#pragma once
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>


struct class_statistic {
    uint32_t count_outdoor = 0; // ������� ��� ���� ����� ����������? (������������ ��� �����������)
    uint32_t total_words = 0; // ������� ���� ��������� ��� ����� ������?
    std::unordered_map<std::string, uint32_t> words; // ������� ��� ��������� ������ ����� ��� ����� ������?
};

void get_num_line(std::string& line, uint32_t& num_line);
void get_title(std::ifstream& file, std::string& title);
void get_text(std::ifstream& file, std::string& line, uint32_t& num_line, std::string& text);