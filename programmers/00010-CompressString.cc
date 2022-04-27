#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int r[501][1001];

int solution(string s) {
    int answer = INT32_MAX;

    for (int i = 1; i <= s.length(); ++i) {
        bool previous = false;
        int count = 0;
        int total = 0;
        int len = s.length();
        for (int j = i; j < s.length(); j += i) {
            //cout << "j :" << j << endl;
            if (s.compare(j - i, i, s, j, i) == 0 && previous == false) {
                //cout << "first" << endl;
                previous = true;
                count += 2;
            } else if (previous && s.compare(j - i, i, s, j, i) == 0) {
                //cout << "second" << endl;
                count++;
            } else {
                //cout << "third : " << count << endl;
                previous = false;
                if (count > 0) {
                    len -= (count * i);

                    total += to_string(count).length();
                    total += i;
                    //cout << "in : " << len << " " << total << endl;
                }
                count = 0;
            }
        }
        //끝에서 끝났을 경우.
        if (count > 0) {
            len -= (count * i);
            total += to_string(count).length();
            total += i;
        }
        //cout << i << " " << total << " " << len << endl;
        answer = std::min(answer, total + len);
    }

    return answer;
}