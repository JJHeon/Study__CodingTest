#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
int n, t;
vector<int> rsts;

int main(){
    cin >> t;
    for (int i = 0; i < t; ++i){
        cin >> n;

        map<string, int> m;
        vector<string> v;
        string item;
        string category;

        for (int k = 0; k < n; ++k){
            cin >> item >> category;

            if(m.find(category) == m.end()){
            v.push_back(category);
            }

            m[category] += 1;
        }
            
        int rst = 0;
        if(v.size()){
            rst = m[v[0]] + 1;
            for (int j = 1; j < v.size(); ++j){
                rst *= (m[v[j]] + 1);
            }

            rst -= 1;
        }

        rsts.push_back(rst);
    }

    for (auto i : rsts) cout << i << "\n";
    return 0;
}