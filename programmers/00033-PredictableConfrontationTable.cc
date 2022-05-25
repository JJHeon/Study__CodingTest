#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int answer = 0;
    a = a - 1;
    b = b - 1;
    while (a != b) {
        a /= 2;
        b /= 2;
        answer++;
    }
    return answer;
}