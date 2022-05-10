#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

/*
처음에는 stack을 사용했는데, stack은 adapter로 실제 container로 쓰고 있는 근간은 deque이다
deque는 vector에 비해 메모리 사용량이 매우 극심함. (대신 속도는 조금 더 빠름)
채점하는데 있어, 문자열 1,000,000개의 길이를 deque에 담아 처리하는데 각 1바이트로 1024k byte = 1mbyte로 예상했으나
통상 deque는 원소 크기에 비해 8배 메모리가 더 필요하다, default stack size가 256byte임을 감안하면 여유를 감안해도 문제가 생김
실제로 테스트케이스에서 코어 덤프 발생

따라서 벡터를 사용하고 메모리를 예약함으로써 해결
*/

int function(string& str) {
    vector<char> s;
    s.reserve(str.length());

    for (char& c : str) {
        if (s.back() == c)
            s.pop_back();
        else
            s.push_back(c);
    }

    if (s.empty())
        return 1;
    else
        return 0;
}

int solution(string s) {
    int answer = -1;

    answer = function(s);

    return answer;
}