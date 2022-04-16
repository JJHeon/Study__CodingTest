#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const char goForwardAlphabet = 65;
const char goBackwardAlphabet = 91;
int resultRecursive = INT32_MAX;

void Recursive(int value, string& name, const int until, int count, int startPoint) {
    if (until == count) {
        // cout << "end " << value << ", " << resultRecursive <<  endl;
        resultRecursive = min(value, resultRecursive);
        return;
    }
    // Right
    int rightCount = 0;
    for (int i = startPoint + 1;; ++i) {
        rightCount++;
        int ri = i % name.size();
        if (ri == startPoint) break;
        if (name[ri] != 'A') {
            char tmp = name[ri];
            name[ri] = 'A';
            // cout << "count : " << count << ", right, rightcount : " << rightCount << ", value : " << value << endl;
            Recursive(value + rightCount, name, until, count + 1, ri);
            name[ri] = tmp;
            break;
        }
    }
    // left
    int leftCount = 0;
    for (int i = startPoint - 1;; --i) {
        leftCount++;
        int ri = abs(static_cast<int>(name.size()) + i) % name.size();
        // cout << "count : " <<count<<", startpoint : " << startPoint << ", left ri : " << ri << endl;
        if (ri == startPoint) break;
        if (name[ri] != 'A') {
            char tmp = name[ri];
            name[ri] = 'A';
            // cout << "count : " << count << ", left, leftCount : " << leftCount << ", value : " << value << endl;
            Recursive(value + leftCount, name, until, count + 1, ri);
            name[ri] = tmp;
            break;
        }
    }
}

int solution(string name) {
    int answer = 0;
    int requiredCharacterCount = 0;
    for (char ch : name) {
        if (ch != 'A') {
            requiredCharacterCount++;
            int forwardValue = (ch - goForwardAlphabet) % 65;
            int backwardValue = abs(ch - goBackwardAlphabet) % 65;

            int count = min(forwardValue, backwardValue);
            answer += count;
        }
    }
    cout << answer << endl;

    if (name[0] != 'A') {
        name[0] = 'A';
        requiredCharacterCount -= 1;
    }
    Recursive(answer, name, requiredCharacterCount, 0, 0);

    answer = resultRecursive;
    return answer;
}

/*

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

int solution(string name) {
    int answer = 0;
    for (auto ch : name)
        answer += LUT[ch - 'A'];
    int len = name.length();
    int left_right = len - 1;
    for (int i = 0; i < len; ++i) {
        int next_i = i + 1;
        while (next_i < len && name[next_i] == 'A')
            next_i++;
        left_right = min(left_right, i + len - next_i + min(i, len - next_i));
    }
    answer += left_right;
    return answer;
}

조이스틱을 전체적으로 좌우로 움직이는 최소경로를 구하는것은, 어떤 특정 시점에서 (원점에서 출발하여 i번째 위치에 도착한 후,) i번째 위치에서, i번째 위치에서부터 A가 아닌 (우측으로) next_i번째 떨어진 문자로 이동하는 과정에서 좌우로 움직이는 최소 이동횟수를 각 시점마다 탐색해가며 greedy하게 찾는 것이다. (원점에서 출발하여) i번째에서 우측에 있는 A가 아닌 next_i번째 문자를 찾을 때 좌우 이동 총 횟수는 (i) 원점에서 i번째를 먼저 갔다가, 원점으로 되돌아가고 역주행하여 next_i번째로 최종도착한다. (ii) 원점에서 역주행해서 next_i번째에 먼저 갔다가, 원점으로 정주행해서 되돌아가고 i번째에 도착한다, 둘중 하나이다. for문으로 각각의 i에서 그에 상응하는 next_i번째로 가는 길로의 좌우 최소경로를 탐색할때마다, 원점의 관점에서 시작해서 위의 2가지 방법 중 최소경로를 탐색하는 과정(좌우 이동횟수의 min을 찾는 과정. 이를 통해서 특정시점에서의 최소의 좌우이동횟수를 구할 수 있게 된다.)을 하게됨. 최종 left_right값은 어딘가의 i에서 그것의 next_i로 이동할때 최소 좌우 이동횟수의 경로인 (i)또는 (ii)중 하나의 모습일 것임.(즉, i또는 ii의 모습만 나옴. 최소경로니까 i했다가 ii했다가 i했다가 ii했다가 i하는 모습같은건 안나옴). 예를 들어서, [A 2개]C1[A 100개]C2[A 1억개]C3[A 2개] 라고 생각해보면, i=C2, next_i=C3 일때의, 그리고 위의 (ii)방식으로 이동했을때의 시점에서의 left_right값이 greedy하게 도출된 최소 좌우이동횟수의 값이다. 역주행해서 C3찍었다가 원점으로 돌아가고, [A1억개] 앞에있는 C2까지 정주행한 경로가 전반적으로 제일 저렴한 최종 left_right로 나온다. 그 외의 시점에서는 [A1억개]가 꼭 이동경로에 포함되버린다. 특정 시점이란 결국엔 i=C2, next_i=C3 처럼 중간에 A가 무지하게 많은 경우일 때임을 알 수있다. BAB의 경우도 좌우이동횟수 3, BB의 경우도 좌우이동횟수 2로 예외없이 잘 작동함.
*/