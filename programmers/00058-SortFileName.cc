#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;

    stable_sort(files.begin(), files.end(), [](const string& a, const string& b) -> bool {
        int a_ch_i = 0;
        int b_ch_i = 0;
        for (a_ch_i = 0; a_ch_i < a.length(); ++a_ch_i)
            if ('0' <= a[a_ch_i] && a[a_ch_i] <= '9') break;
        for (b_ch_i = 0; b_ch_i < b.length(); ++b_ch_i)
            if ('0' <= b[b_ch_i] && b[b_ch_i] <= '9') break;

        string a_ch = a.substr(0, a_ch_i);
        string b_ch = b.substr(0, b_ch_i);
        transform(a_ch.begin(), a_ch.end(), a_ch.begin(), ::tolower);
        transform(b_ch.begin(), b_ch.end(), b_ch.begin(), ::tolower);
        if (a_ch != b_ch) return a_ch < b_ch;

        int a_num_i = 0;
        int b_num_i = 0;
        for (a_num_i = a_ch_i; a_num_i < a.length(); ++a_num_i)
            if (!('0' <= a[a_num_i] && a[a_num_i] <= '9')) break;
        for (b_num_i = b_ch_i; b_num_i < b.length(); ++b_num_i)
            if (!('0' <= b[b_num_i] && b[b_num_i] <= '9')) break;

        int a_v = stoi(a.substr(a_ch_i, a_num_i - a_ch_i));
        int b_v = stoi(b.substr(b_ch_i, b_num_i - b_ch_i));
        return a_v < b_v;
    });
    answer = files;
    return answer;
}