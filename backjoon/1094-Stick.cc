#include <iostream>

using namespace std;

int a[65];
int x;
int sum = 0;
int rst = 0;

int main() {
    cin >> x;
    a[64] = 1;
    rst = 1;
    sum = 64;
    while (sum != x) {
        int sel = 0;
        int restsum = 0;
        for (int i = 1; i <= 64; ++i)
            if (a[i]) {
                sel = i;
                break;
            }

        if (a[sel] == 2) restsum = sel;
        for (int i = sel + 1; i <= 64; ++i)
            if (a[i]) restsum += i;

        a[sel] -= 1;

        int div = sel / 2;
        if (restsum + div >= x)
            a[div] += 1;
        else
            a[div] += 2;

        sum = 0;
        rst = 0;
        for (int i = 1; i <= 64; ++i)
            if (a[i]) {
                sum += a[i] * i;
                rst += a[i];
            }
    }
    cout << rst;

    return 0;
}