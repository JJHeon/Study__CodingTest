#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int n;
int sc1, sc2, pvm = -1, pvt, m1, m2;
int tm, hm;
string hmstr;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        cin >> tm >> hmstr;

        hm = atoi(hmstr.substr(0, 2).c_str()) * 60 + atoi(hmstr.substr(3, 2).c_str());

        if (tm == 1)
            sc1 += 1;
        else
            sc2 += 1;

        if (pvm == -1 && sc1 != sc2) {
            pvm = hm;
            pvt = tm;
        } else if (pvm != -1 && sc1 == sc2) {
            int m = hm - pvm;
            if (pvt == 1)
                m1 += m;
            else
                m2 += m;
            pvm = -1;
        }
    }
    if(pvm != -1){
        int m = 48 * 60 - pvm;
        if (pvt == 1) m1 += m;
        else
            m2 += m;
    }

    printf("%02d:%02d\n", m1 / 60, m1 % 60);
    printf("%02d:%02d\n", m2 / 60, m2 % 60);

    return 0;
}