#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N], pre[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, a;
        cin >> n;
        map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            cin >> a;
            ++mp[a % 10];
        }
        int ok = 0;
        for (auto i = mp.begin(); i != mp.end(); ++i) {
            if (i->second >= 3 && (i->first * 3) % 10 == 3) {
                ok = 1;
            }
            auto j = i;
            ++j;
            for (; j != mp.end(); ++j) {
                if (i->second >= 2 && (i->first * 2 + j->first) % 10 == 3) {
                    ok = 1;
                }
                if (j->second >= 2 && (i->first + j->first * 2) % 10 == 3) {
                    ok = 1;
                }
                auto k = j;
                ++k;

                for (; k != mp.end(); ++k) {
                    if ((i->first + j->first + k->first) % 10 == 3) {
                        ok = 1;
                    }
                }
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}