#include <iostream>
#include <string>
using namespace std;
string INPUT;

string GetCroatiaAlphabet(string input, int& count, string const& word) {
    string target = input;
    for (string::size_type k; (k = target.find(word)) != string::npos;) {
        string tmp;
        tmp += target.substr(0, k);
        for (int i = 0; i != word.length(); ++i) tmp.push_back('0');
        tmp += target.substr(k + word.length());
        target.swap(tmp);
        count++;
    }

    return target;
}

int main() {
    cin >> INPUT;
    int count = 0;

    string after_1 = GetCroatiaAlphabet(INPUT, count, "c=");
    // cout << "1 : c= :" << after_1 << "  count : " << count << endl;
    string after_2 = GetCroatiaAlphabet(after_1, count, "c-");
    // cout << "2 : c- :" << after_2 << "  count : " << count << endl;
    string after_3 = GetCroatiaAlphabet(after_2, count, "dz=");
    // cout << "3 : dz= :" << after_3 << "  count : " << count << endl;
    string after_4 = GetCroatiaAlphabet(after_3, count, "d-");
    // cout << "4 : d- :" << after_4 << "  count : " << count << endl;
    string after_5 = GetCroatiaAlphabet(after_4, count, "lj");
    // cout << "5 : lj :" << after_5 << "  count : " << count << endl;
    string after_6 = GetCroatiaAlphabet(after_5, count, "nj");
    // cout << "6 : nj :" << after_6 << "  count : " << count << endl;
    string after_7 = GetCroatiaAlphabet(after_6, count, "s=");
    // cout << "7 : s= :" << after_7 << "  count : " << count << endl;
    string after_8 = GetCroatiaAlphabet(after_7, count, "z=");
    // cout << "8 : z= :" << after_8 << "  count : " << count << endl;

    for (auto itr = after_8.begin(); itr != after_8.end(); ++itr) {
        if (*itr != '0') count++;
    }

    cout << count;
    return 0;
}
