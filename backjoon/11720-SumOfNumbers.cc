#include <iostream>

#include <string>
#include <cstdlib>

using namespace std;
long long RESULT;
int N;
string INPUT;
int main() {
    cin >> N;
    cin >> INPUT;
    for (int i = 0; i != N; ++i) {
        RESULT += static_cast<int>(INPUT[i] - 48);
    }
    cout << RESULT;
    return 0;
}