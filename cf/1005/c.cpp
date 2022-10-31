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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 120000;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    set<int> bin;
    map<int, int> mp;
    for (int i = 0; i < 31; ++i) {
        bin.insert(1 << i);
    }
    for (int i = 1; i <= n; ++i) {
        ++mp[a[i]];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        bool ok = false;
        for (auto& j : bin) {
            auto p = mp.find(j - a[i]);
            if (p == mp.end()) {
                continue;
            }
            if (p->first == a[i]) {
                if (p->second >= 2) {
                    ok = true;
                    break;
                }
            } else {
                ok = true;
                break;
            }
        }
        if (!ok) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}