#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N];
map<int, int> mp;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ++mp[a[i]];
        }
        int w = 0;
        for (auto &i : mp) {
            if (i.second >= 2) {
                ++w;
            }
        }
        int ans = mp.size() - w >> 1;
        ans += w;
        if (mp.size() - w) {
            ++w;
            ans = max(ans, ((int)mp.size() - w) / 2 + w);
        }
        cout << ans << endl;
    }
    return 0;
}
/*
5
3 3 5 6 6

*/