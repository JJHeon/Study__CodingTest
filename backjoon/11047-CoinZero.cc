#include <iostream>
#include <vector>

using namespace std;
int N, K;
vector<int> VALUE;
int RESULT;
int main() {
    cin >> N >> K;

    VALUE.resize(N);
    for (int i = 0; i != N; ++i) cin >> VALUE[i];

    for (vector<int>::reverse_iterator ritr = VALUE.rbegin(); ritr != VALUE.rend(); ritr++) {
        // cout << K << " " << *ritr << endl;
        RESULT += (K / *ritr);
        K %= *ritr;
    }
    cout << RESULT;
    return 0;
}