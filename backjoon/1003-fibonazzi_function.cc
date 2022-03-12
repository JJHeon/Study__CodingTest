/*
@Title		 :
@Name		 :
@First Update:
@ETC         : This code use input_reader library for auto testing that read text as numbers or alphabet
*/

/* ====================== Auto Mode Settings ===================== */
#define TRUE 1
#define FALSE 0
#define AUTO_TEST_MODE FALSE
#define DEBUG_INPUT_READER FALSE
const char* test_case_file_path = "../test_case/test.txt";

/* -------------- For Auto Test(Don't touch CODES) --------------- */
#if AUTO_TEST_MODE
#include <sstream>
#include <string>
#include "input_reader.h"
#endif

#include <iostream>
#include <array>
#include <vector>
/* ====================== UserCode Header ===================== */

int T;

std::vector<int> ONE = std::vector(41, -1);
std::vector<int> ZERO = std::vector(41, -1);

/**
 * @parm input : test_case input
 */
/* ========================= UserCode ========================= */
#if AUTO_TEST_MODE
int Solution(std::stringstream& input) {
    // Input ,Using input param if you are AUTO_TEST_MODE

#else
int Solution() {
    // Input, // Write input process using std::cin
    std::cin >> T;

#endif

    // Default Value
    ONE[0] = 0;
    ONE[1] = 1;
    ZERO[0] = 1;
    ZERO[1] = 0;

    int test;
    // Partial Input
    for (int i = 0; i < T; ++i) {
        std::cin >> test;

        // Process
        for (int i = 2; i <= test; ++i) {
            if (ONE[i] != -1 && ZERO[i] != -1) continue;
            ONE[i] = ONE[i - 2] + ONE[i - 1];
            ZERO[i] = ZERO[i - 2] + ZERO[i - 1];
        }
        std::cout << ZERO[test] << " " << ONE[test] << std::endl;
    }

    // Result
    return 0;
}

/* -------------- For Auto Test(Don't touch CODES) --------------- */
#if AUTO_TEST_MODE == FALSE
// For Website Compiler
int main() {
    Solution();

    return 0;
}

#else
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

#endif