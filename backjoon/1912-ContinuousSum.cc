/*
@Title		 : 백준
@Name		 : 연속합
@First Update: 22.03.01
@ETC         : This code use input_reader library for auto testing that read text as numbers or alphabet
*/

/* ====================== Auto Mode Settings ===================== */
#define TRUE 1
#define FALSE 0
#define AUTO_TEST_MODE FALSE
#define DEBUG_INPUT_READER FALSE
const char* test_case_file_path = "../test_case/backjoon/1912-ContinuousSum.txt";

/* -------------- For Auto Test(Don't touch CODES) --------------- */
#if AUTO_TEST_MODE
#include <sstream>
#include <string>
#include "input_reader.h"
#endif

#include <iostream>

/* ====================== UserCode Header ===================== */
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int RES = INT32_MIN;
int N;
int GET_INPUT[100001];
int MAP[100001];
/**
 * @parm input : test_case input
 */
/* ========================= UserCode ========================= */

#if AUTO_TEST_MODE
int Solution(std::stringstream& input) {
    // Input ,Using input param if you are AUTO_TEST_MODE
    input >> N;
    for (int i = 1; i <= N; ++i) input >> MAP[i];
#else
int Solution() {
    // Input, // Write input process using std::cin
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> MAP[i];
#endif

    // Process

    if (MAP[1] > RES) RES = MAP[1];

    for (int i = 2; i <= N; ++i) {
        if (MAP[i - 1] > 0 && MAP[i - 1] + MAP[i] > 0) MAP[i] = MAP[i - 1] + MAP[i];
        if (MAP[i] > RES) RES = MAP[i];
    }

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