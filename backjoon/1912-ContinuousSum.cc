#include <iostream>
#include <cstdint>
#include <cstring>

using namespace std;

int n;
int a[100004];
int rst = INT32_MIN;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    if (rst < a[1]) rst = a[1];
    for (int i = 2; i <= n; ++i) {
        if (a[i - 1] > 0 && a[i - 1] + a[i] > 0) a[i] = a[i - 1] + a[i];
        if (rst < a[i]) rst = a[i];
    }

    cout << rst;
    return 0;
}