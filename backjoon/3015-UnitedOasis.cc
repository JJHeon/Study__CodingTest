#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int n;
stack<int> s;
int mp[500001];
long long rst;
map<int, int> m;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> mp[i];

    s.push(mp[0]);
    m[mp[0]] = 1;
    for (int i = 1; i < n; ++i) {
        if (s.size()) {
            if (s.top() > mp[i]) {
                rst += 1;
            } else if (s.top() == mp[i]) {
                rst += accumulate(m.begin(), m.upper_bound(mp[i]), 0ll, [](auto sum, auto& pair) {
                    return sum + pair.second;
                });

                if (m.lower_bound(mp[i] + 1) != m.end()) rst += 1;
            }

            else if (s.top() < mp[i]) {
                while (s.size() && s.top() < mp[i]) {
                    rst += m[s.top()];
                    m.erase(s.top());
                    s.pop();
                }

                if (s.size()) rst += accumulate(m.begin(), m.upper_bound(mp[i]), 0ll, [](auto sum, auto& pair) {
                                  return sum + pair.second;
                              });

                if (m.lower_bound(mp[i] + 1) != m.end()) rst += 1;
            }
        }
        if (!s.size() || s.top() != mp[i]) s.push(mp[i]);

        m[mp[i]] += 1;
    }

    cout << rst;

    return 0;
}