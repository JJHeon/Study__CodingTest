#include <iostream>
#include <cstdio>
#include <string>
#include <deque>

using namespace std;

int t;
string p;
int n;
int mp[102];
string in;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int k = 0; k < t; ++k) {
        deque<int> dq;

        cin >> p;
        cin >> n;
        cin >> in;

        int num = -1;
        int cnt = 0;
        for (int i = 0; i < in.length(); ++i) {
            if (num == -1 && in[i] >= '0' && in[i] <= '9') {
                num = i;
                cnt++;
            } else if (num != -1 && in[i] >= '0' && in[i] <= '9')
                cnt++;
            else if (num != -1 && (in[i] == ',' || in[i] == ']')) {
                dq.push_back(atoi(in.substr(num, cnt).c_str()));
                num = -1;
                cnt = 0;
            }
        }

        bool order = false;
        bool keep = true;
        for (int i = 0; i < p.length(); ++i) {
            if (p[i] == 'R') {
                order = !order;
            } else if (p[i] == 'D') {
                if (dq.size() == 0) {
                    keep = false;
                    break;
                }

                if (!order)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }

        if (!keep) {
            cout << "error\n";
            continue;
        }

        if (dq.size() == 0) {
            cout << "[]\n";
        } else if (!order) {
            cout << "[";
            for (int i = 0; i < dq.size() - 1; ++i) {
                cout << dq[i] << ",";
            }
            cout << dq[dq.size() - 1] << "]\n";
        } else {
            cout << "[";
            for (int i = dq.size() - 1; i > 0; --i) {
                cout << dq[i] << ",";
            }
            cout << dq[0] << "]\n";
        }
    }

    return 0;
}
