#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    LL n;
    cin >> n;
    LL ans = n;
    vector<int> a = {2, 5, 11, 13};
    for (int i = 1; i < (1 << a.size()); ++i) {
        LL cnt = 1, flag = 1;
        for (int j = 0; j < a.size(); ++j) {
            if (i >> j & 1) {
                cnt *= a[j];
                flag = -flag;
            }
        }
        ans -= n / cnt * flag;
    }
    cout << ans << endl;
    return 0;
}