#include <string>
#include <vector>
#include <iostream>
using namespace std;

// O(n^2)
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    int size = prices.size();

    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = i + 1; j < size; ++j) {
            count++;
            if (prices[j] < prices[i])
                break;
        }
        answer[i] = count;
    }

    return answer;
}
/* 정답 - O(N)
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for(int i=0;i<size;i++){
        while(!s.empty()&&prices[s.top()]>prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = size-s.top()-1;
        s.pop();
    }
    return answer;
}
*/