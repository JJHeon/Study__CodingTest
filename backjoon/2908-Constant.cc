#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

string INPUT_1;
string INPUT_2;

int main() {
    cin >> INPUT_1 >> INPUT_2;

    swap(INPUT_1[0], INPUT_1[2]);
    swap(INPUT_2[0], INPUT_2[2]);
    int one = stoi(INPUT_1);
    int two = stoi(INPUT_2);

    one > two ? cout << one : cout << two;

    return 0;
}