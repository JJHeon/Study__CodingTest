#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> v;
    int v_size = 0;
    unordered_map<string, int> st;

    for (auto& city : cities) {
        string t = city;
        transform(t.begin(), t.end(), t.begin(), ::tolower);

        // for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
        // cout << "\n";

        if (st.find(t) != st.end()) {
            answer += 1;
            int i = st[t] + 1;
            // cout << "target : " << t << " " << i << endl;
            for (; i < v.size(); ++i) st[v[i]]--;
            v.erase(v.begin() + st[t]);
            v.push_back(t);
            st[t] = v.size() - 1;

        } else {
            answer += 5;
            if (v.size() < cacheSize) {
                v.push_back(t);
                st.insert(make_pair(t, v.size() - 1));
            } else if (cacheSize != 0) {
                for (int i = 0; i < v.size(); ++i) st[v[i]]--;

                st.erase((*v.begin()));

                v.erase(v.begin());
                v.push_back(t);

                st.insert(make_pair(t, v.size() - 1));
            }
        }
    }

    return answer;
}