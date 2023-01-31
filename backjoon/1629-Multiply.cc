#include <iostream>
#include <stack>

using namespace std;
int a, b, c;
long long cnt = 1;
long long one;
long long two;
long long rst;
int main() {
    cin >> a >> b >> c;

    // 1
    one = 1 * a % c;
    // 2
    two = one * a % c;

    if (b == 1) {
        cout << one;
        return 0;
    } else if (b == 2) {
        cout << two;
        return 0;
    }

    stack<int> s;
    while (b > 0) {
        s.push(b);
        b /= 2;
    }

    cnt = 0;
    rst = 1;
    while (!s.empty()) {
        long long b2 = s.top();
        // cout << b2 << "\n";
        s.pop();
        while (cnt < b2 && cnt != b2) {
            if (cnt != 0 && cnt * 2 <= b2) {
                rst = rst * rst % c;
                cnt *= 2;
            } else {
                rst = rst * one % c;
                cnt += 1;
            }
        }
    }
    cout << rst;

    return 0;
}