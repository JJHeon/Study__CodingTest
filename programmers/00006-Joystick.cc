#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    string nameFollower(name.length(), 'A');
    // nameFollower[0] = name[0];
    // cout << nameFollower << endl;

    const char goForwardAlphabet = 65;
    const char goBackwardAlphabet = 91;

    int startPos = 0;
    for (int count = 0; count < nameFollower.length(); ++count) {
        // Search position
        int searchOffset = 0;
        int selectedPos = -1;
        while (searchOffset <= nameFollower.length() / 2) {
            const int rightNextPos = (startPos + searchOffset) % nameFollower.length();
            const int leftNextPos = startPos - searchOffset >= 0 ? startPos - searchOffset : (nameFollower.length()) + (startPos - searchOffset);

            // cout << ":"<< rightNextPos << " " << leftNextPos << endl;
            if (name[leftNextPos] != nameFollower[leftNextPos]) {
                selectedPos = leftNextPos;
                startPos = leftNextPos;
                answer += searchOffset;
                // cout << "left" << endl;
                break;
            } else if (name[rightNextPos] != nameFollower[rightNextPos]) {
                selectedPos = rightNextPos;
                startPos = rightNextPos;
                answer += searchOffset;
                // cout<< "right" << endl;
                break;
            } else
                searchOffset++;
        }

        if (selectedPos == -1) break;
        // cout <<"|"<< selectedPos << endl;
        nameFollower[selectedPos] = name[selectedPos];
        int forwardCount = abs(name[selectedPos] - goForwardAlphabet);
        int backwardCount = abs(name[selectedPos] - goBackwardAlphabet);
        int minCount = min(forwardCount, backwardCount);
        answer += minCount;
    }

    return answer;
}