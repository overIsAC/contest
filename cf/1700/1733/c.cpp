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
const int N = 3 + 1e5;

int n, k, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<PII> ans;
        if (a[1] & 1) {
            int last = 0;
            for (int i = n; i >= 1; --i) {
                if (a[i] & 1) {
                    if (last) {
                        ans.push_back({i, last});
                    }
                    last = i;
                }
            }
            for (int i = 2; i <= n; ++i) {
                if (a[i] % 2 == 0) {
                    ans.push_back({1, i});
                }
            }
        } else {
            int last = 0;
            for (int i = n; i >= 1; --i) {
                if (a[i] % 2 == 0) {
                    if (last) {
                        ans.push_back({i, last});
                    }
                    last = i;
                }
            }
            for (int i = 2; i <= n; ++i) {
                if (a[i] % 2) {
                    ans.push_back({1, i});
                }
            }
        }
        cout << ans.size() << endl;
        for (auto &i : ans) {
            cout << i.first << ' ' << i.second << endl;
        }
    }
    return 0;
}