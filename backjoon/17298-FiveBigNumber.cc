#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int n;
int arr[1000002];
int rst[1000002];
stack<int> stk;

int main() {
    cin >> n;
    memset(rst, -1, sizeof(rst));
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        while (stk.size() && arr[stk.top()] < arr[i]) {
            rst[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }

    for (int i = 0; i < n; ++i) cout << rst[i] << " ";

    return 0;
}