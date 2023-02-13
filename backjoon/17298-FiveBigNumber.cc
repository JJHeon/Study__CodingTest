#include <iostream>

using namespace std;

int n;
int arr[1000002];
int rst[1000002];
int mx = 0;

int f(int i, int v) {
    for (int j = i + 1; j <= n; ++j) {
        if (rst[j] != -1 && v < rst[j]) return rst[j];
    }
    return -1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    rst[n] = -1;
    mx = arr[n];

    for (int i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i + 1])
            rst[i] = arr[i + 1];
        else if (arr[i] < mx) {
            rst[i] = f(i, arr[i]);
            continue;
        } else
            rst[i] = -1;

        if (arr[i] > mx) mx = arr[i];
    }

    for (int i = 1; i <= n; ++i) cout << rst[i] << " ";

    return 0;
}