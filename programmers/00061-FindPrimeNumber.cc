#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

void Recursive(int count, string num, string& numbers, vector<bool>& visited, set<int>& s) {
    if (count == numbers.size()) {
        return;
    }

    for (int i = 0; i < numbers.size(); ++i) {
        if (visited[i]) continue;

        visited[i] = true;
        string n = num + numbers[i];
        s.insert(stoi(n));
        Recursive(count + 1, n, numbers, visited, s);
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> visited(numbers.size(), false);
    set<int> s;

    Recursive(0, "", numbers, visited, s);

    for (auto i = s.begin(); i != s.end(); ++i) {
        // cout << (*i) << endl;
        int num = (*i);
        if (num == 0 || num == 1) continue;

        bool is_prime = true;
        for (int d = 2; d < num; ++d)
            if (num % d == 0) {
                is_prime = false;
                break;
            }
        if (!is_prime) continue;
        answer++;
    }

    return answer;
}