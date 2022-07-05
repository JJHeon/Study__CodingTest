#include <string>
#include <vector>
#include <iostream>
#include <array>

using namespace std;


long long solution(int n) {
    long long answer = 0;
    //array<long long, 2001> arr;
    vector<long long> arr(2001, 0);

    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; ++i) 
        arr[i] = (arr[i - 1] + arr[i - 2]) % 1234567;

    answer = arr[n];
    return answer;
}