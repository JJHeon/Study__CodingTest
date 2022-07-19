#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int main() {
    int n;
    vector<int> result_all;
    multiset<int> s;

    cin >> n;

    int first_in;
    cin >> first_in;
    s.insert(first_in);
    result_all.push_back(first_in);

    auto itr = s.begin();

    for (int i = 1; i < n; ++i) {
        int in, result;
        cin >> in;

        s.insert(in);

        if (*itr > in) itr--;

        if (s.size() % 2 == 0) {
            int one = *itr;
            itr++;
            int two = *itr;

            result = one < two ? one : two;
        } else {
            result = *itr;
        }

        result_all.push_back(result);
    }
    for (auto v : result_all) cout << v << "\n";
    return 0;
}