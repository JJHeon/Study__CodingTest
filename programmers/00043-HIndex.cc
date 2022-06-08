#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());

    int h = 0;
    for (int i = 0; i < citations.size(); ++i) {
        const int more_than = citations.size() - i;
        const int others = citations.size() - more_than;

        const int select = citations[i];
        for (; h <= select; ++h){
            if (h <= more_than && others <= h) answer = max(answer, h);
        }
    }

    return answer;
}