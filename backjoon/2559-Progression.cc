#include <iostream>
#include <algorithm>

using namespace std;

#define INF INT32_MAX
int pro[100004];
int sum[100004];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> pro[i];

    fill(&sum[0], &sum[0] + 100004, INF);
    sum[0] = 0;
    for (int i = 0; i < k; ++i) sum[0] += pro[i];
    
    for (int i = 1; i + k - 1 < n; ++i) {
        sum[i] = sum[i - 1] - pro[i - 1] + pro[i + k - 1];
    }

    // for (int i = 0; i < n; ++i) cout << sum[i] << " ";
    // cout << "\n";

    int rst = sum[0];
    for (int i = 0; i < n; ++i) {
        if(sum[i] == INF) continue;
        rst = max(rst, sum[i]);
    }
    cout << rst;
    return 0;
}