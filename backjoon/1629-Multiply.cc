#include <iostream>
#include <stack>

using namespace std;
long long a, b, c;
long long rst;
long long recursive(long long b2) {
    if (b2 == 1) return a % c;

    long long ret = recursive(b2 / 2);
    ret = (ret * ret) % c;
    if (b2 & 1) ret = (ret * a) % c;
    return ret;
}

int main() {
    cin >> a >> b >> c;

    rst = recursive(b);

    cout << rst << "\n";

    return 0;
}