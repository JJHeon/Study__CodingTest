#include <iostream>
#include <string>

#include "input_reader.h"

int main() {
    input_reader::InputPracticeProblem input;

    input.ReadFile("../test_case/test.txt");
    input.ConstructStream();
    //auto& stream = input.GetInputData();

    input.PrintFullyExtractedStream();

    // std::string word;
    // for (auto& ptr : stream) {
    //     while (*ptr >> word) {
    //         std::cout << word << std::endl;
    //     }
    // }
}