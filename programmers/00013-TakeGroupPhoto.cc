#include <string>
#include <vector>
#include <map>
#include <array>
#include <cmath>
#include <iostream>

using namespace std;

void DFS(int& answer, map<const char, int>& m, array<const char, 8>& name, vector<bool>& validate, vector<string>& data, int count) {
    if (count == 8) {
        answer++;
        return;
    }

    for (int i = 0; i < 8; ++i) {
        if (m[name[i]] != -1) continue;
        m[name[i]] = count;

        for (auto itr = data.cbegin(); itr != data.cend(); ++itr) {
            if ((*itr)[0] == name[i] || (*itr)[2] == name[i]) {
                const int a = m[(*itr)[0]];
                const int b = m[(*itr)[2]];
                const int gap = (*itr)[4] - 48;
                if (a != -1 && b != -1) {
                    switch ((*itr)[3]) {
                        case '=':
                            if (abs(a - b) - 1 != gap) {
                                goto OUT_DOUBLE_FOR;
                            }

                            break;

                        case '<':
                            if (!(abs(a - b) - 1 < gap)) goto OUT_DOUBLE_FOR;
                            break;
                        case '>':
                            if (!(abs(a - b) - 1 > gap)) goto OUT_DOUBLE_FOR;

                            break;
                    }
                }
            }
        }
        DFS(answer, m, name, validate, data, count + 1);
    OUT_DOUBLE_FOR:
        m[name[i]] = -1;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    map<const char, int> m;
    array<const char, 8> name{'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<bool> validate(data.size(), false);
    for (int i = 0; i < 8; ++i) m[name[i]] = -1;

    DFS(answer, m, name, validate, data, 0);

    return answer;
}