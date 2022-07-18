#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    vector<string> result_all;

    for (int tc = 0; tc < t; ++tc) {
        int start_y, start_x;
        int end_y, end_x;

        string result = "sad";

        cin >> n;
        cin >> start_y >> start_x;

        vector<pair<int, int>> store(n + 1);
        vector<bool> visited(n + 1);
        store[0] = make_pair(start_y, start_x);
        for (int c = 1; c <= n; ++c) {
            int y, x;
            cin >> y >> x;
            store[c] = make_pair(y, x);
        }
        cin >> end_y >> end_x;

        queue<tuple<int, int, int, int>> q;
        q.push(make_tuple(start_y, start_x, 0, 20));
        while (!q.empty()) {
            auto [y, x, idx, beer] = q.front();
            q.pop();
            if (visited[idx]) continue;

            int dist_y = end_y - y;
            int dist_x = end_x - x;
            if (abs(dist_y) + abs(dist_x) <= 50 * beer) {
                result = "happy";
                break;
            }
            visited[idx] = true;

            for (int c = 1; c <= n; ++c) {
                if (visited[c]) continue;

                int dist = abs(store[c].first - y) + abs(store[c].second - x);
                if (dist > beer * 50) continue;

                q.push(make_tuple(store[c].first, store[c].second, c, 20));
            }
        }

        result_all.push_back(result);
    }
    for (auto s : result_all) cout << s << "\n";

    return 0;
}