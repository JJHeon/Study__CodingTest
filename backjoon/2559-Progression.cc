#include <iostream>
#include <algorithm>

using namespace std;

#define INF INT32_MAX
int sum[100004];
int n, k;
int temp;
int rst = INT32_MIN;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> temp;
        sum[i] = sum[i - 1] + temp;
    }
    for (int i = k; i <= n; i++){
        rst = max(rst, sum[i] - sum[i - k]);
    }
    cout << rst << "\n";
    return 0;
}