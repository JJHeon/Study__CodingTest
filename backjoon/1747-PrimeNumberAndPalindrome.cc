#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int N;

int main() {
    long long result = 0;
    cin >> N;
    for (long long i = N; i <= INT64_MAX; ++i) {
        if(i == 1) continue;

        long long q = (long long)sqrt((double)i);

        bool is_prime = true;
        for (long long j = 2; j <= q; ++j){
            if (i % j == 0){
                is_prime = false;
                break;
            }
        }
        if(!is_prime) continue;
        bool is_palindrome = true;
        string s = to_string(i);
        for (int offset = 0; offset < s.size() / 2; ++offset) {
            if (s[offset] != s[s.size() - 1 - offset]) {
                is_palindrome = false;
                break;
            }
        }
        if (is_palindrome) {
            result = i;
            break;
        }
    }
    cout << result << endl;
    return 0;
}