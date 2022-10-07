#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

int N;
int M;

int main() {
    map<int, int> m;

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int input;
        scanf("%d", &input);
        m[input] = 1;
    }

    cin >> M;
    for (int i = 1; i <= M; ++i) {
        int input;
        scanf("%d", &input);
        if (m[input])
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}