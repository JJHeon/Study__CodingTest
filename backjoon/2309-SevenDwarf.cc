#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int dwarf[9];
int n, r;

void combi(int start, vector<int> v){
    if(v.size() == r){
        int sum = 0;
        for (auto l : v){
            sum += l;
        } 
        if (sum == 100) {
          sort(v.begin(), v.end());
          for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
          exit(0);
        }

        return;
    }

    for (int i = start + 1; i < n; ++i){
        v.push_back(dwarf[i]);
        combi(i, v);
        v.pop_back();
    }
}



int main(){
    n = 9;
    r = 7;
    for (int i = 0; i < 9; ++i)
        cin >> dwarf[i];

    vector<int> v;
    combi(-1, v);

    return 0;
}
