#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <set>
using namespace std;

int SearchMin(const int N, bool* spt_set, int* dist) {
    int min = INT32_MAX;
    int pos = -1;
    for (int i = 0; i < N; ++i) {
        if (!spt_set[i] && dist[i] <= min) {
            min = dist[i];
            pos = i;
        }
    }
    return pos;
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    vector<vector<int>> edges(N, vector<int>(N, 0));
    for (auto& r : road) {
        if (edges[r[0] - 1][r[1] - 1] != 0) {
            edges[r[0] - 1][r[1] - 1] = min(edges[r[0] - 1][r[1] - 1], r[2]);
            edges[r[1] - 1][r[0] - 1] = min(edges[r[1] - 1][r[0] - 1], r[2]);
        } else {
            edges[r[0] - 1][r[1] - 1] = r[2];
            edges[r[1] - 1][r[0] - 1] = r[2];
        }
    }

    bool spt_set[N];
    int dist[N];

    constexpr int kINF = INT32_MAX;
    fill_n(spt_set, N, false);
    fill_n(dist, N, kINF);

    dist[0] = 0;

    for (int cnt = 0; cnt < N; ++cnt) {
        int u = SearchMin(N, spt_set, dist);

        spt_set[u] = true;

        for (int v = 0; v < N; ++v) {
            if (!spt_set[v] && edges[u][v] && dist[u] != kINF && dist[u] + edges[u][v] < dist[v])
                dist[v] = dist[u] + edges[u][v];
        }
    }

    for (int i = 0; i < N; ++i)
        if (dist[i] <= K) answer++;


    return answer;
}