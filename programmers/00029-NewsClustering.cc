#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

constexpr int kINTER = 1;
constexpr int kNOT_ALPHBET = -1;
constexpr int kNOT_VISITED = 0;

void Convert(string& s, int status[], int& num_not) {
    const int len = s.length();

    for (int i = 0; i < len - 1; ++i) {
        char* c1 = &s[i];
        char* c2 = &s[i + 1];
        *c1 = std::tolower(static_cast<unsigned char>(*c1));
        *c2 = std::tolower(static_cast<unsigned char>(*c2));
        if (*c1 < 97 || *c1 > 122) {
            status[i] = kNOT_ALPHBET;
            num_not++;
            continue;
        }
        if (*c2 < 97 || *c2 > 122) {
            status[i] = kNOT_ALPHBET;
            num_not++;
            continue;
        }
    }
}

int solution(string str1, string str2) {
    int answer = 0;

    int str1_status[1000] = {
        0,
    };
    int str2_status[1000] = {
        0,
    };
    int str1_not_alph = 0;
    int str2_not_alph = 0;

    Convert(str1, str1_status, str1_not_alph);
    Convert(str2, str2_status, str2_not_alph);

    const int str1_len = str1.length();
    const int str2_len = str2.length();

    cout << "1 : " << str1 << endl;
    cout << "2 : " << str2 << endl;

    int intersect_count = 0;
    for (int i = 0; i < str1_len - 1; ++i) {
        if (str1_status[i] == kNOT_VISITED) {
            for (int j = 0; j < str2_len - 1; ++j) {
                if (str2_status[j] != kNOT_VISITED) continue;

                if (str1[i] == str2[j] && str1[i + 1] == str2[j + 1]) {
                    str1_status[i] = kINTER;
                    str2_status[j] = kINTER;
                    intersect_count++;
                    break;
                }
            }
        }
    }
    
    int union_count = intersect_count + (str1_len - 1 - intersect_count - str1_not_alph) + (str2_len - 1 - intersect_count - str2_not_alph);

    if(str1_not_alph == str1_len -1 && str2_not_alph == str2_len - 1){
        answer = 65536;
    } else {
        double cal = intersect_count / (double)union_count;
        answer = cal * 65536;
    }

    return answer;
}