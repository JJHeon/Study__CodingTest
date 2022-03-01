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
const char* test_case_file_path = "../test_case/backjoon/9251-LCS.txt";

/* -------------- For Auto Test(Don't touch CODES) --------------- */
#if AUTO_TEST_MODE
#include <sstream>
#include <string>
#include "input_reader.h"
#endif

#include <iostream>

/* ====================== UserCode Header ===================== */
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int RES;

/**
 * @parm input : test_case input
 */
/* ========================= UserCode ========================= */
#if AUTO_TEST_MODE
int Solution(std::stringstream& input) {
    // Input ,Using input param if you are AUTO_TEST_MODE
    string firstString;
    string secondString;
    input >> firstString >> secondString;
#else
int Solution() {
    // Input, // Write input process using std::cin
    string firstString;
    string secondString;
    cin >> firstString >> secondString;
#endif

    // Process
    vector<vector<int>> memorize(secondString.length() + 1, vector<int>(firstString.length() + 1, 0));

    for (int i = 0; i < secondString.length(); ++i) {
        for (int j = 0; j < firstString.length(); ++j) {
            int memorize_i = i + 1;
            int memorize_j = j + 1;

            if (secondString[i] == firstString[j]) {
                int fowradIndexJ = memorize_j - 1;
                int fowradIndexI = memorize_i - 1;

                memorize[memorize_i][memorize_j] = memorize[fowradIndexI][fowradIndexJ] + 1;
            } else {
                int bigger = std::max(memorize[memorize_i - 1][memorize_j], memorize[memorize_i][memorize_j - 1]);
                memorize[memorize_i][memorize_j] = bigger;
            }
        }
    }
    RES = memorize[secondString.length()][firstString.length()];
    // Result
    cout << RES;
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