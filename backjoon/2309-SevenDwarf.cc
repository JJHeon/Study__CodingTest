#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int dwarf[9];
int n = 9, r = 2;
int sum;
pair<int, int> pick;
void solve() {
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < i; j++){
            if(sum - dwarf[i]-  dwarf[j] == 100){
                pick = {i, j};
                return;
            }
        }
    }
}

int main(){
    vector<int> v;
    for (int i = 0; i < 9; ++i) {
        cin >> dwarf[i];
        sum += dwarf[i];
    }
    solve();
    for (int i = 0; i < 9; i++){
        if(pick.first == i || pick.second == i) continue;
        v.push_back(dwarf[i]);
    }

    sort(v.begin(), v.end());
    for (auto i : v) cout << i << " ";
    

    return 0;
}
