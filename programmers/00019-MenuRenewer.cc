#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string, int> hash;
    vector<string> cdi;

    for (auto& order : orders) {
        int t = 1;
        sort(order.begin(), order.end());
        for (int i = 0; i < order.length(); ++i) t *= 2;

        for (int i = 1; i < t; ++i) {
            string tmp = "";
            for (int j = 0; j < order.length(); ++j) {
                if (i & (1 << j)) tmp += order[j];
            }

            if (tmp.length() < 2) continue;
            hash[tmp]++;
            if (hash[tmp] == 1) cdi.push_back(tmp);

            // cout << tmp << " " << hash[tmp] << "\n";
        }
    }

    sort(cdi.begin(), cdi.end());
    for (int i = 0; i < course.size(); ++i) {
        int max_value = INT32_MIN;
        vector<string> buff;
        for (int j = 0; j < cdi.size(); ++j) {
            if (hash[cdi[j]] < 2) continue;
            if (cdi[j].length() != course[i]) continue;

            if (max_value < hash[cdi[j]]) {
                max_value = hash[cdi[j]];
                buff.clear();
                buff.push_back(cdi[j]);

            } else if (max_value == hash[cdi[j]]) {
                buff.push_back(cdi[j]);
            }
        }
        cout << endl;

        for (auto& str : buff) answer.push_back(str);
    }

    sort(answer.begin(), answer.end());
    return answer;
}
/* -- 다른 사람 답 -- */
// map<string,int> combi;

// void combination(string src, string crs, int depth) {
//     if (crs.size() == depth) combi[crs]++;

//     else for (int i = 0; i < src.size(); i++)
//         combination(src.substr(i+1), crs+src[i], depth);
// }

// vector<string> solution(vector<string> orders, vector<int> course) {
//     vector<string> answer;

//     for (string &order : orders)
//         sort(order.begin(), order.end());

//     for (int crs : course) {
//         for (string order : orders)
//             combination(order, "", crs);

//         int sup = 0;
//         for (auto it : combi)
//             sup = max(sup, it.second);
//         for (auto it : combi)
//             if (sup >= 2 && it.second == sup)
//                 answer.push_back(it.first);
//         combi.clear();
//     }

//     sort(answer.begin(), answer.end());
//     return answer;
// }
