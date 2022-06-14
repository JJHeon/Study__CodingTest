#include <string>
#include <vector>
#include <stack>
#include <cstdint>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = INT32_MAX;

    for (int selected = 0; selected < n - 1; ++selected) {
        stack<int> s;
        bool visited[n];

        fill_n(visited, n, false);

        s.push(1);

        while (!s.empty()) {
            auto v = s.top();
            s.pop();
            visited[v - 1] = true;

            for (auto edge = 0; edge < n - 1; edge++) {
                if(edge == selected) continue;
                if(wires[edge][0] != v && wires[edge][1] != v) continue;

                int next = wires[edge][0] == v ? wires[edge][1] : wires[edge][0];
                if(visited[next - 1]) continue;

                s.push(next);
            }
        }

        int count = 0;
        for (int i = 0; i < n; ++i)
            if (visited[i]) count++;

        int diff = abs(count - (n - count));
        answer = min(diff, answer);
    }

    return answer;
}