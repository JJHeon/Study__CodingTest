#include <iostream>
#include <vector>


using namespace std;

int t;
int input;
vector<int> rst;

int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> input;

        long long five = 5;
        long long val = input;
        long long cnt = 0;

        while(val >= five){
            cnt += val / five;
            five *= 5;
        }
        rst.push_back(cnt);
    }

    for (auto val : rst) cout << val << "\n";
    return 0;
}