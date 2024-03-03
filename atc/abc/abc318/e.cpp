#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3e5;

int n, a[N];
map<int, vector<int>> mp;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        mp[a[i]].push_back(i);
    }

    LL ans = 0;
    for (auto& [i, j] : mp) {
        for (int k = 1; k < j.size(); ++k) {
            ans += (LL)(j[k] - j[k - 1] - 1) * k * (j.size() - k);
        }
    }
    cout << ans << endl;

    return 0;
}