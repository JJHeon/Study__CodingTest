#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int n;
int prime[4000002];
vector<int> primes;
int rst;
deque<int> q;

void get_prime() {
    for (int i = 2; i <= n; ++i) {
        if (prime[i]) continue;
        primes.push_back(i);
        for (int j = 2; i * j <= n; ++j) prime[i * j] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    get_prime();

    int value = 0;
    int i = 0;
    while (i != primes.size()) {
        if (value < n) {
            value += primes[i];

            q.push_back(primes[i]);
            i++;
        } else if (value > n) {
            if (q.size()) {
                value -= q.front();
                q.pop_front();
            }
        }
        if (value == n) {
            value -= q.front();
            q.pop_front();
            rst++;
        }
    }

    while (q.size()) {
        value -= q.front();
        q.pop_front();
        if (value == n) rst++;
    }

    cout << rst;

    return 0;
}