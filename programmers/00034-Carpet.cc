#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int y = 3, x = 0;
    while (true) {
        if ((yellow + brown) % y != 0){
            y++;
            continue;
        } 
        x = (yellow + brown) / y;
        if (y * x != yellow + brown || (y - 2) * (x - 2) != yellow || ((y - 2) * 2) + (x * 2) != brown)
            y++;
        else
            break;
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}