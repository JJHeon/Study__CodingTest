#include <iostream>
#include <set>

using namespace std;

int rst, n, k;
int mp[102];
set<int> st;

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; ++i) cin >> mp[i];

    for (int i = 0; i < k;) {
        if (st.size() < n) {
            st.insert(mp[i++]);
        }

        else if (st.find(mp[i]) == st.end()) {
            int t = -1;
            int mm = 0;

            for (auto it : st) {
                bool is_end = false;

                for (int j = i; j < k; ++j) {
                    if (it == mp[j]) {
                        is_end = true;
                        if (mm < j - i) {
                            t = it;
                            mm = j - i;
                        }
                        break;
                    }
                }
                if (!is_end) {
                    t = it;
                    break;
                }
            }
            st.erase(t);
            rst++;
        } else
            i++;
    }
    cout << rst;
    return 0;
}