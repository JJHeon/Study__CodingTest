/*
@Title		:
@Name		:
@Revision	:
@ETC		:
*/

#include <iostream>

#include <sstream>
#include <string>
#include "input_reader.h"

/* ------------------------- Auto Test ------------------------- */
/* --------------------- Don't touch codes --------------------- */
#define AUTO_TEST_MODE 1
#define DEBUG_INPUT_READER 0

constexpr char* test_case_file_path = "../test_case/test.txt";
int Solution(std::stringstream& input);

int main() {
    input_reader::InputPracticeProblem inputs;
    inputs.ReadFile(test_case_file_path);
    inputs.ConstructStream();
    auto& input_list = inputs.GetInputData();

#if DEBUG_INPUT_READER
    inputs.PrintFullyExtractedStream();
    return 0;

#else
    // Normal Execution
    for (auto& ptr : input_list) {
        std::string word;

        // Read Header Number
        *ptr >> word;
        std::cout << word << " Result : ";

        // Execution User Solution
        if (Solution(*ptr) != 0) {
            std::cout << "Error occur" << std::endl;
            break;
        }
        std::cout << std::endl;
    }
#endif

    return 0;
}

/**
 * @parm input : test_case input
 */
/* ========================= UserCode ========================= */

int Solution(std::stringstream& input) {
// Input
#if AUTO_TEST_MODE
// Using input param
#else
    // Don't use input parm
    // Write input process using std::cin

#endif

    // Process

    // Result
    return 0;
}