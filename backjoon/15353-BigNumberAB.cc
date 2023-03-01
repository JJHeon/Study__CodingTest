#include <iostream>

#include <string>

#include <algorithm>

using namespace std;

string as, bs;

string rst;

int a, b;

int prv;

int main() {
    cin >> as >> bs;

    a = as.length() - 1;

    b = bs.length() - 1;

    for (; a >= 0 && b >= 0;) {
        int av = as[a] - '0';

        int bv = bs[b] - '0';

        rst.push_back(((av + bv + prv) % 10) + '0');

        prv = (av + bv + prv) / 10;

        a--;

        b--;
    }

    for (; a >= 0;) {
        int av = as[a] - '0';

        rst.push_back(((av + prv) % 10) + '0');

        prv = (av + prv) / 10;

        a--;
    }

    for (; b >= 0;) {
        int bv = bs[b] - '0';

        rst.push_back(((bv + prv) % 10) + '0');

        prv = (bv + prv) / 10;

        b--;
    }

    if (prv != 0) rst.push_back(prv + '0');

    reverse(rst.begin(), rst.end());

    cout << rst << "\n";

    return 0;
}