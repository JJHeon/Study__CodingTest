#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <array>

using namespace std;
long long maximum = INT64_MIN;

void Tokenize(string& expression, vector<long long>& numbers, vector<char>& operators) {
    const char* str = expression.c_str();
    char* copied = (char*)malloc(sizeof(char) * std::strlen(str) + 1);
    std::strcpy(copied, str);

    const char* delim = "+*-";
    char* token = std::strtok(copied, delim);
    int pos = -1;
    while (token != NULL) {
        numbers.push_back(stoi(token));
        pos += (strlen(token) + 1);
        if (pos < strlen(str)) operators.push_back(str[pos]);

        token = std::strtok(NULL, delim);
    }

    free(copied);
}

void Recursive(vector<long long> numbers, vector<char> operators, array<bool, 3>& validate) {
    // cout << numbers.size() << " " << operators.size() << endl;
    if (numbers.size() == 1 && operators.size() == 0) {
        numbers[0] = numbers[0] < 0 ? numbers[0] * -1 : numbers[0];
        maximum = std::max(maximum, (long long)numbers[0]);
        // cout << "in : " << numbers[0] <<  endl;
        return;
    }

    //+
    if (!validate[0]) {
        // cout << "+" << endl;
        vector<long long> copied = numbers;
        vector<char> op_copied = operators;

        for (int i = 0; i < op_copied.size(); ++i) {
            if (op_copied[i] == '+') {
                copied[i] = copied[i] + copied[i + 1];

                auto copied_itr = copied.begin() + i + 1;
                copied.erase(copied_itr);
                op_copied.erase(op_copied.begin() + i);
                i--;
            }
        }

        validate[0] = true;
        Recursive(copied, op_copied, validate);
        validate[0] = false;
    }

    //-
    if (!validate[1]) {
        // cout << "-" << endl;
        vector<long long> copied = numbers;
        vector<char> op_copied = operators;

        for (int i = 0; i < op_copied.size(); ++i) {
            if (op_copied[i] == '-') {
                copied[i] = copied[i] - copied[i + 1];

                auto copied_itr = copied.begin() + i + 1;
                copied.erase(copied_itr);
                op_copied.erase(op_copied.begin() + i);
                i--;
            }
        }

        validate[1] = true;
        Recursive(copied, op_copied, validate);
        validate[1] = false;
    }
    //+
    if (!validate[2]) {
        // cout << "*" << endl;
        vector<long long> copied = numbers;
        vector<char> op_copied = operators;

        for (int i = 0; i < op_copied.size(); ++i) {
            if (op_copied[i] == '*') {
                copied[i] = copied[i] * copied[i + 1];

                auto copied_itr = copied.begin() + i + 1;
                copied.erase(copied_itr);
                op_copied.erase(op_copied.begin() + i);
                i--;
            }
        }

        validate[2] = true;
        Recursive(copied, op_copied, validate);
        validate[2] = false;
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> numbers;
    vector<char> operators;
    Tokenize(expression, numbers, operators);

    // Debug
    /*
    for (auto a : numbers)
        cout << a << " ";
    cout << endl;

    for (auto c : operators)
        cout << c << " ";
    cout << endl;
    */
    array<bool, 3> validate{false, false, false};
    Recursive(numbers, operators, validate);
    answer = maximum;

    return answer;
}
/* 다른 사람 해답 (참고안함)
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> op;

    int idx = 0;
    for(int i=0;i<expression.size();i++){
        char ch = expression[i];
        if(ch == '*' | ch == '+' | ch == '-'){
            op.push_back(ch);
            nums.push_back(stoi(expression.substr(idx,i-idx)));
            idx = i+1;
        }else if(i == expression.size()-1){
            nums.push_back(stoi(expression.substr(idx,i-idx+1)));
        }
    }

    string prior[6] = {
        "*+-", "*-+",
        "+*-", "+-*",
        "-*+", "-+*",
    };

    for(int i=0;i<6;i++){
        vector<long long> temp_nums = nums;
        vector<char> temp_op = op;
        string pr = prior[i];
        for(int j=0;j<3;j++){
            for(int k=0;k<temp_op.size();k++){
                if(pr[j] == temp_op[k]){
                    if(pr[j] == '*'){
                        temp_nums[k] = temp_nums[k]*temp_nums[k+1];
                        temp_nums.erase(temp_nums.begin()+k+1);
                    }else if(pr[j] == '+'){
                        temp_nums[k] = temp_nums[k]+temp_nums[k+1];
                        temp_nums.erase(temp_nums.begin()+k+1);
                    }else if(pr[j] == '-'){
                        temp_nums[k] = temp_nums[k]-temp_nums[k+1];
                        temp_nums.erase(temp_nums.begin()+k+1);
                    }
                    temp_op.erase(temp_op.begin()+k--);
                }
            }
        }
        answer = max(answer, abs(temp_nums[0]));
    }

    return answer;
}


*/