#include <iostream>

using namespace std;

int m[104];
int a, b, c;
int pee[4];
int main() {
    cin >> pee[1] >> pee[2] >> pee[3];

    for (int i = 0; i < 3; ++i){
        int s, e;
        cin >> s >> e;

        for (int j = s; j < e; ++j) m[j] += 1;
    }
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sum += (pee[m[i]]) * m[i];
    }


    cout << sum;
}