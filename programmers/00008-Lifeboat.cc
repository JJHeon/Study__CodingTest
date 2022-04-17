#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> HASH(241, vector<int>());

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int count = 0;
    int i = 0;
    int j = people.size() - 1;
    while(i < people.size()){
        if(people[i] + people[j] <= limit){
            i++;
            j--;
            count++;
        }
        else{
            j--;
            count++;
        }

        if (i > j) break;
        else if(i==j) {
            count++;
            break;
        }
    }
    answer = count;
    return answer;
}