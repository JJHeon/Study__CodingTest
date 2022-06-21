#include <string>
#include <vector>
#include <iostream>

using namespace std;

void Recursive(int count, string str, const string& word, int& total, int& answer) {
    if (count > 5 || answer != 0) {
        return;
    }
    if (str.length() > 0) {
        total++;
        // cout << str << endl;
        if (str == word) {
            answer = total;
            return;
        }
    }

    static const string vowel = "AEIOU";
    for (int i = 0; i < vowel.length(); ++i) {
        Recursive(count + 1, str + vowel[i], word, total, answer);
    }
}

int solution(string word) {
    int answer = 0;
    int total = 0;
    Recursive(0, "", word, total, answer);
    return answer;
}