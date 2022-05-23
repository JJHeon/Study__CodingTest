#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    multiset<int> set;
    for (auto& val : scoville) set.insert(val);

    multiset<int>::iterator it1 = set.begin();
    while (*it1 < K) {
        multiset<int>::iterator it2 = ++set.begin();
        if (it2 == set.end()) {
            answer = -1;
            break;
        }
        int rlt = (*it1) + (*it2) * 2;
        if (rlt < 1) {
            answer = -1;
            break;
        }

        set.erase(it1);
        set.erase(it2);
        set.insert(rlt);
        answer++;

        /*
        for(auto i = set.begin(); i != set.end(); ++i) {
            cout << *i << " ";
        }
        cout << endl;
        */
        it1 = set.begin();
    }
    
    return answer;
}