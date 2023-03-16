#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

deque<char> dq[1000];
int t, k;
string in;
int num;
int way;
vector<pair<int, int>> com;
int rst;

void rotate(deque<char>& q, int w) {
    char tmp;
    if (w == -1) {
        tmp = q.front();
        q.pop_front();
        q.push_back(tmp);
    } else {
        tmp = q.back();
        q.pop_back();
        q.push_front(tmp);
    }
}

void left(int n, int w) {
    if (n < 0) return;
    // cout << "left\n";
    bool l = false;
    if (n - 1 >= 0)
        l = dq[n][6] != dq[n - 1][2] ? true : false;

    if (l) left(n - 1, w * -1);

    rotate(dq[n], w);
}
void right(int n, int w) {
    if (n >= t) return;
    // cout << "right\n";
    bool r = false;
    if (n + 1 < t)
        r = dq[n][2] != dq[n + 1][6] ? true : false;

    if (r) right(n + 1, w * -1);

    rotate(dq[n], w);
}

void Sol(int n, int w) {
    bool r = false;
    bool l = false;
    if (n + 1 < t)
        r = dq[n][2] != dq[n + 1][6] ? true : false;
    if (n - 1 >= 0)
        l = dq[n][6] != dq[n - 1][2] ? true : false;

    if (r) right(n + 1, w * -1);
    if (l) left(n - 1, w * -1);

    rotate(dq[n], w);
}

int main() {
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> in;
        dq[i].assign(in.begin(), in.end());
    }

    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> num >> way;
        com.push_back({num, way});
    }

    for (int i = 0; i < k; ++i) {
        auto [n, w] = com[i];

        Sol(n - 1, w);

        // cout << i << "\n";
        // for(int j = 0; j <t; ++j){
        // 	for(int jj = 0; jj < dq[i].size(); ++jj){
        // 		cout << dq[j][jj] << " ";
        // 	}
        // 	cout <<"\n";
        // }
        // cout <<"\n\n";
    }

    for (int i = 0; i < t; ++i)
        if (dq[i].front() == '1') rst++;

    cout << rst;
    return 0;
}