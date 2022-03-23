#include <iostream>
#include <vector>
#include <string>

using namespace std;

string INPUT;
int RESULT;

int main() {
    cin >> INPUT;
    int startPos = 0;
    string::iterator minusPos = INPUT.end();
    for (auto itr = INPUT.begin(); itr != INPUT.end(); ++itr) {
        if (*itr == '+') {
            string::size_type t = itr - INPUT.begin();
            string valueStr = INPUT.substr(startPos, t);
            startPos = t + 1;
            RESULT += stoi(valueStr);
        } else if (*itr == '-') {
            string::size_type t = itr - INPUT.begin();
            string valueStr = INPUT.substr(startPos, t);
            startPos = t + 1;
            RESULT += stoi(valueStr);

            minusPos = (++itr);
            break;
        } else if (itr == INPUT.end() - 1) {
            string valueStr = INPUT.substr(startPos, INPUT.size());
            RESULT += stoi(valueStr);
        }
    }

    // cout << RESULT << endl;
    int minusSum = 0;
    for (auto itr = minusPos; itr != INPUT.end(); ++itr) {
        if (*itr == '+' || *itr == '-') {
            string::size_type t = itr - INPUT.begin();

            string valueStr = INPUT.substr(startPos, t);
            startPos = t + 1;
            minusSum += stoi(valueStr);
        } else if (itr == INPUT.end() - 1) {
            string valueStr = INPUT.substr(startPos, INPUT.size());
            minusSum += stoi(valueStr);
        }
    }
    RESULT -= minusSum;
    cout << RESULT << endl;

    return 0;
}