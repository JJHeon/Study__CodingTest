#include <iostream>

using namespace std;
int n, m;

int arr[15004];

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int rst = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j){
            if (arr[i] + arr[j] == m) rst++;
        }
    }
    cout << rst << "\n";

    return 0;
}