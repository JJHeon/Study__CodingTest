#include <iostream>
#include <vector>
#include <tuple>
#include <cstdint>
#include <queue>
#include <list>

using namespace std;

int F, S, G, U, D;

int main() {
    cin >> F >> S >> G >> U >> D;

    queue<pair<int, int>> q;
    vector<int> visited(1000001, INT32_MAX);

    q.push(make_pair(S, 0));
    while(!q.empty()){
        auto [floor, count] = q.front();
        q.pop();
        if(F < floor) continue;
        if(floor < 1 || 1000000 < floor) continue;
        if(visited[floor] <= count) continue;
        
        visited[floor] = count;

        q.push(make_pair(floor + U, count + 1));
        q.push(make_pair(floor - D, count + 1));
    }
    if (visited[G] == INT32_MAX){
        cout << "use the stairs\n";
        return 0;
    }
    else {
        cout << visited[G] << "\n";
        return 0;
    }

    return 0;
}