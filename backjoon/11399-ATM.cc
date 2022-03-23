#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> PEOPLE;
int RESULT;

int main() {
    cin >> N;
    PEOPLE.resize(N);
    for (auto& p : PEOPLE)
        cin >> p;

    sort(PEOPLE.begin(), PEOPLE.end());

    int acumulateTime = 0;
    for (auto p : PEOPLE) {
        RESULT += (p + acumulateTime);
        acumulateTime += p;
    }

    cout << RESULT;
    return 0;
}