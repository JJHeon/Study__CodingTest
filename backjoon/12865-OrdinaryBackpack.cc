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

/* ====================== UserCode Header ===================== */
#include <cstdint>
#include <algorithm>
/**
 * @parm input : test_case input
 */
/* ========================= UserCode ========================= */
using namespace std;

using WV = struct {
    int weight;
    int value;
};

int MAP[101][100001];
WV IN[101];
int N;
int K;
int RES = INT32_MIN;
#if AUTO_TEST_MODE
int Solution(std::stringstream& input) {
    // Input ,Using input param if you are AUTO_TEST_MODE

#else
int Solution() {
    // Input, // Write input process using std::cin
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        cin >> IN[i].weight >> IN[i].value;

#endif
    // Process
    for (int i = 1; i <= N; ++i) {
        // 1-1
        for (int j = 0; j <= K; ++j) {
            // 1-2

            int possibleWeight = j - IN[i].weight;
            int sumValue = 0;
            if (possibleWeight >= 0) sumValue = IN[i].value + MAP[i - 1][possibleWeight];

            MAP[i][j] = max(MAP[i - 1][j], sumValue);
        }
    }

    // Result
    cout << MAP[N][K] << endl;
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