#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N;
int M;
vector<vector<int>> MAP;
vector<int> TARGET;

int main() {
    cin >> N >> M;

    MAP.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) cin >> MAP[i][j];

    int in;
    TARGET.resize(N, 0);
    for (int i = 0; i < M; ++i) {
        cin >> in;
        TARGET[in - 1] = 1;
    }

    string result = "NO";
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        vector<int> visited(N, 0);
        q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (visited[node]) continue;
            visited[node] = 1;

            for (int j = 0; j < N; ++j) {
                if (node == j) continue;

                if (!MAP[node][j]) continue;
                if (visited[j]) continue;

                q.push(j);
            }
        }
        bool is_connected = true;
        for (int j = 0; j < N; ++j) {
            if (TARGET[j] == 1 && visited[j] == 0) {
                is_connected = false;
                break;
            }
        }

        if (is_connected) {
            result = "YES";
            // for (int y = 0; y < N; ++y) cout << visited[y] << " ";
            // cout << endl;
            // for (int y = 0; y < N; ++y) cout << TARGET[y] << " ";
            // cout << endl;
            // break;
        }
    }
    cout << result << endl;
    return 0;
}