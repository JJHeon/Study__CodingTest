#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size());
    unordered_map<string, vector<int>> hash;

    for (auto item = info.begin(); item != info.end(); ++item) {
        int pos = item - info.begin();
        string lang;
        string position;
        string experience;
        string favorit;
        int score = 0;
        stringstream in(*item);
        in >> lang >> position >> experience >> favorit >> score;

        hash[lang + position + experience + favorit].push_back(score);
        hash["-" + position + experience + favorit].push_back(score);
        hash[string("-") + "-" + experience + favorit].push_back(score);
        hash["-" + position + "-" + favorit].push_back(score);
        hash["-" + position + experience + "-"].push_back(score);
        hash[string("-") + "-" + "-" + favorit].push_back(score);
        hash[string("-") + "-" + experience + "-"].push_back(score);
        hash[string("-") + position + "-" + "-"].push_back(score);
        hash[string("-") + "-" + "-" + "-"].push_back(score);

        hash[lang + "-" + experience + favorit].push_back(score);
        hash[lang + string("-") + "-" + favorit].push_back(score);
        hash[lang + string("-") + experience + "-"].push_back(score);
        hash[lang + string("-") + "-" + "-"].push_back(score);

        hash[lang + position + "-" + favorit].push_back(score);
        hash[lang + position + string("-") + "-"].push_back(score);
        hash[lang + position + experience + "-"].push_back(score);
    }

    string l[4] = {"cpp", "java", "python", "-"};
    string p[3] = {"backend", "frontend", "-"};
    string e[3] = {"junior", "senior", "-"};
    string f[3] = {"chicken", "pizza", "-"};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                for (int q = 0; q < 3; q++) {
                    sort(hash[l[i] + p[j] + e[k] + f[q]].begin(), hash[l[i] + p[j] + e[k] + f[q]].end());
                }
            }
        }
    }

    for (auto item = query.begin(); item != query.end(); ++item) {
        int pos = item - query.begin();

        string lang;
        string position;
        string experience;
        string favorit;
        string an;
        int score = 0;
        stringstream in(*item);
        in >> lang >> an >> position >> an >> experience >> an >> favorit >> score;

        vector<int>& v = hash[lang + position + experience + favorit];
        answer[pos] = v.end() - lower_bound(v.begin(), v.end(), score);
    }

    return answer;
}
