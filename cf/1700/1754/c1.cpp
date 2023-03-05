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

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        if (n & 1) {
            cout << -1 << endl;
            continue;
        }
        vector<PII> ans;
        for (int i = 1; i < n; ++i, ++i) {
            if (a[i] * a[i + 1] < 0) {
                ans.push_back({i, i});
                ans.push_back({i + 1, i + 1});
            } else {
                ans.push_back({i, i + 1});
            }
        }
        cout << ans.size() << endl;
        for (auto &i : ans) {
            cout << i.first << ' ' << i.second << endl;
        }
    }
    return 0;
}