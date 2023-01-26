#include <iostream>
#include <string>

using namespace std;

int a[26];
string s;
string rst;

int main () {
    cin >> s;
    for (auto c : s) {
        a[c - 'A']++;
    }

    int maximum = -1;
    int max_index = -1;
    int count_odd = 0;
    bool odd = s.length() % 2 == 1 ? true : false;
    for (int i = 0; i < 26; ++i) {
        if(odd){
            if(a[i] % 2 != 0){
                count_odd++;
                if(count_odd == 2) {
                    cout << "I'm Sorry Hansoo";
                    return 0;
                }
            }
        }
        else{
            if(a[i] % 2 != 0) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
        if (maximum <= a[i]){
            max_index = i;
            maximum = a[i];
        }
    }

    for (int i = 0; i < s.length() / 2; ++i){
        for (int j = 0; j < 26; ++j){
            if(a[j] > 1){
                s[i] = 'A' + j;
                s[s.length() - 1 - i] = 'A' + j;
                a[j] -= 2;

                break;
            }
        }
    }
    for (int i = 0; i < 26; ++i){
        if(a[i] > 0) {
            s[s.length() / 2] = 'A' + i;
        }
    }
    cout << s << "\n";

    return 0;
}