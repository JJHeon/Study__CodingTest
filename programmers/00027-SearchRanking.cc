#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

using dat = struct dat {
    int s;
    int l;
    int p;
    int e;
    int f;
};

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<dat> values(info.size() + 1);
    unordered_map<string, int> name_converter;
    name_converter["java"] = 3;
    name_converter["python"] = 2;
    name_converter["cpp"] = 1;
    name_converter["-"] = 0;
    name_converter["backend"] = 2;
    name_converter["frontend"] = 1;
    name_converter["junior"] = 2;
    name_converter["senior"] = 1;
    name_converter["pizza"] = 2;
    name_converter["chicken"] = 1;
    unordered_map<string, vector<int>> la;
    unordered_map<string, vector<int>> po;
    unordered_map<string, vector<int>> ex;
    unordered_map<string, vector<int>> fa;
    vector<pair<int, int>> scores;
    // input
    for (auto item = info.begin(); item != info.end(); ++item) {
        int pos = item - info.begin();
        string lang;
        string position;
        string experience;
        string favorit;
        int score = 0;
        stringstream in(*item);

        in >> lang >> position >> experience >> favorit >> score;
        scores.push_back(make_pair(score, pos));
        la[lang].push_back(pos);
        po[position].push_back(pos);
        ex[experience].push_back(pos);
        fa[favorit].push_back(pos);
    }
    sort(scores.begin(), scores.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
        if (a.first < b.first)
            return true;
        else
            return false;
    });
    sort(la["java"].begin(), la["java"].end());
    sort(la["python"].begin(), la["python"].end());
    sort(la["cpp"].begin(), la["cpp"].end());
    sort(po["backend"].begin(), po["backend"].end());
    sort(po["frontend"].begin(), po["frontend"].end());
    sort(ex["junior"].begin(), ex["junior"].end());
    sort(ex["senior"].begin(), ex["senior"].end());
    sort(fa["pizza"].begin(), fa["pizza"].end());
    sort(fa["chicken"].begin(), fa["chicken"].end());

    /*
    sort(values.begin(), values.end(), [](const struct dat& a, const struct dat& b) {
        if (a.s < b.s)
            return true;
        else
            return false;
    });
    */

    /*
        int cache[4][3][3][3][50001];
        int index = 0;

        for (auto i = values.begin(); i != values.end(); ++i) {
            int index = i - values.begin();
            int l = i->l;
            int p = i->p;
            int e = i->e;
            int f = i->f;

            if (index - 1 >= 0) {
                cache[l][p][e][f][index] = cache[l][p][e][f][index - 1] + 1;
                cache[0][0][0][0][index] = cache[0][0][0][0][index - 1] + 1;
                cache[l][0][0][0][index] = cache[l][0][0][0][index - 1] + 1;
                cache[0][p][0][0][index] = cache[0][p][0][0][index - 1] + 1;
                cache[0][0][e][0][index] = cache[0][0][e][0][index - 1] + 1;
                cache[0][0][0][f][index] = cache[0][0][0][f][index - 1] + 1;
                cache[l][p][0][0][index] = cache[l][p][0][0][index - 1] + 1;
                cache[l][0][e][0][index] = cache[l][0][e][0][index - 1] + 1;
                cache[l][0][0][f][index] = cache[l][0][0][f][index - 1] + 1;
                cache[0][p][e][0][index] = cache[0][p][e][0][index - 1] + 1;
                cache[0][p][0][f][index] = cache[0][p][0][f][index - 1] + 1;
                cache[0][0][e][f][index] = cache[0][0][e][f][index - 1] + 1;
                cache[l][p][e][0][index] = cache[l][p][e][0][index - 1] + 1;
                cache[l][p][0][f][index] = cache[l][p][0][f][index - 1] + 1;
                cache[l][0][e][f][index] = cache[l][0][e][f][index - 1] + 1;
                cache[0][p][e][f][index] = cache[0][p][e][f][index - 1] + 1;
            } else {
                cache[l][p][e][f][index] = 1;
                cache[0][0][0][0][index] = 1;
                cache[l][0][0][0][index] = 1;
                cache[0][p][0][0][index] = 1;
                cache[0][0][e][0][index] = 1;
                cache[0][0][0][f][index] = 1;
                cache[l][p][0][0][index] = 1;
                cache[l][0][e][0][index] = 1;
                cache[l][0][0][f][index] = 1;
                cache[0][p][e][0][index] = 1;
                cache[0][p][0][f][index] = 1;
                cache[0][0][e][f][index] = 1;
                cache[l][p][e][0][index] = 1;
                cache[l][p][0][f][index] = 1;
                cache[l][0][e][f][index] = 1;
                cache[0][p][e][f][index] = 1;
            }
            index++;
      }
      */

    for (auto item = query.begin(); item != query.end(); ++item) {
        string lang;
        string position;
        string experience;
        string favorit;
        string an;
        int score = 0;
        stringstream in(*item);

        in >> lang >> an >> position >> an >> experience >> an >> favorit >> score;
        auto start_itr = find_if(scores.begin(), scores.end(), [&score](const pair<int, int>& a) -> bool {
            if (a.first >= score)
                return true;
            else
                false;
        });
        auto itr1 = start_itr;
        if (lang != "-")

        // int count = 0;
        // int a = name_converter[lang];
        // int b = name_converter[position];
        // int c = name_converter[experience];
        // int d = name_converter[favorit];

        // for (auto i = values.lower_bound(score); i != values.end(); ++i) {
        //     const int p = (*i).second;
        //     if(cache[a][b][c][d][score]){
        //         count = cache[a][b][c][d][score];
        //         break;
        //     }
        //     if (lang != "-" && langs[p] != a) continue;
        //     if (position != "-" && positions[p] != b) continue;
        //     if (experience != "-" && experiences[p] != c) continue;
        //     if (favorit != "-" && favorits[p] != d) continue;
        //     count++;
        // }
        // answer.push_back(count);
        // if (cache[a][b][c][d][score] == 0) cache[a][b][c][d][score] = count;
    }
    return answer;
}