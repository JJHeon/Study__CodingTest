#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> INPUT;
int main() {
    int count = 0;
    string s;
    while (cin >> s) {
        count++;
    }
    cout << count;
    return 0;
}