#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maximum = 0;
bool visited[9];
void Recursive(int count, int k, vector<vector<int>>& dungeons) {
    for (int i = 0; i < dungeons.size(); ++i) {
        if (visited[i]) continue;
        if (k < dungeons[i][0]) continue;

        visited[i] = true;

        Recursive(count + 1, k - dungeons[i][1], dungeons);

        visited[i] = false;
    }
    maximum = std::max(count, maximum);
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    Recursive(0, k, dungeons);
    answer = maximum;
    return answer;
}
