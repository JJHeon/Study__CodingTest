#include <iostream>
#include <deque>
#include <unordered_set>

using namespace std;

long long rst;
deque<int> dq;
unordered_set<int> st;
int n;
int mp[100002];
int vl[100002];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> mp[i];

    for (int i = 0; i < n; i++) {
        if (st.find(mp[i]) != st.end()) {
            while (dq.size() && dq.front() != mp[i]) {
                st.erase(dq.front());
                dq.pop_front();
            }
            if (dq.size()) dq.pop_front();
            dq.push_back(mp[i]);

            vl[i] = dq.size();
        } else {
            st.insert(mp[i]);
            dq.push_back(mp[i]);
            vl[i] = dq.size();
        }
    }

    for (int i = 0; i < n; ++i) rst += vl[i];

    cout << rst;

    return 0;
}
