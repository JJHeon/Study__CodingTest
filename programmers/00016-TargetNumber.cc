#include <string>
#include <vector>

using namespace std;

void Dfs(int count, const int until, int sum, vector<int>& numbers, const int target, int& num_of_way) {
    if (count == until) {
        if (sum == target) num_of_way++;
        return;
    }

    Dfs(count + 1, until, sum + numbers[count], numbers, target, num_of_way);

    Dfs(count + 1, until, sum - numbers[count], numbers, target, num_of_way);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    Dfs(0, numbers.size(), 0, numbers, target, answer);

    return answer;
}