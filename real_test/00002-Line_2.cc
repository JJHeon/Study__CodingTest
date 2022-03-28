#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cctype>
using namespace std;

int solution(vector<string> sentences, int n) {
    int answer = -1;
    int selected_ch = 0;
    int hash_alphabet[200];
    vector<string> keys(sentences.size(), "");
    vector<int> scores(sentences.size());

    // Search key
    int count_str = 0;
    for (const auto& str : sentences) {
        int key_num = 0;
        bool is_need_shift = false;
        int upper_letter_count = 0;
        int lower_leeter_count = 0;
        int space_letter_count = 0;
        int score = 0;
        keys.push_back(string(""));
        for (const char& chr : str) {
            //공백 처리
            if (chr == ' ') {
                space_letter_count++;
                continue;
            }
            int is_lower = chr - 96;
            int hash_pos = 0;
            // 대문자, 소문자 구분
            if (is_lower < 0) {
                upper_letter_count++;
                is_need_shift = true;
            } else {
                lower_leeter_count++;
            }
            if (hash_alphabet[hash_pos] != 0) continue;
            hash_alphabet[hash_pos]++;
            key_num++;
            keys[count_str].append({static_cast<char>(tolower(chr))});
            // keys[count_str].append("s");
        }

        if (is_need_shift) {
            key_num += 1;                 // add shift key
            keys[count_str].append("0");  //'0' mean space
        }
        if (key_num > n)
            score = 0;
        else
            score = upper_letter_count * 2 + lower_leeter_count + space_letter_count;

        scores[count_str++] = score;
    }

    // find sentence

    for (const auto& key : keys) {
        int score = 0;
        bool find_shift = false;
        if (key.find('0') != key.end()) find_shift = true;

        int count_sentences = 0;
        for (const auto& str : sentences) {
            for (const char& chr : key) {
                if (chr == '0' || chr == ' ') continue;  // cut space, shift
                if (str.find({chr}) == str.end()) goto NOT_MATCH_KEY;
            }
            score += scores[count_sentences++];
        }
        answer = max(answer, score);
    NOT_MATCH_KEY:
        score = 0;
    }

    cout << answer << endl;
    return answer;
}
