#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int n;
int vmp[16], vmf[16], vms[16], vmv[16], vprice[16];
int mp, mf, ms, mv;
int rst = INT32_MAX;
vector<vector<int>> rstv;
int inmp, inmf, inms, inmv, inprice;

int main() {
    cin >> n;
    cin >> mp >> mf >> ms >> mv;

    for (int i = 0; i < n; ++i)
        cin >> vmp[i] >> vmf[i] >> vms[i] >> vmv[i] >> vprice[i];

    for (int i = 1; i < 1 << n; ++i) {
        int smp = 0, smf = 0, sms = 0, smv = 0, sprice = 0;
        vector<int> list;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                smp += vmp[j];
                smf += vmf[j];
                sms += vms[j];
                smv += vmv[j];
                sprice += vprice[j];
                list.push_back(j + 1);
            }
        }

        if (smp >= mp && smf >= mf && sms >= ms && smv >= mv) {
            if (rst > sprice) {
                rst = sprice;
                rstv.clear();
                rstv.push_back(list);
            } else if (rst == sprice)
                rstv.push_back(list);
        }
    }

    sort(rstv.begin(), rstv.end());

    if (rst != INT32_MAX) {
        cout << rst << "\n";
        for (auto it : rstv[0]) cout << it << " ";
    } else
        cout << "-1\n";

    return 0;
}