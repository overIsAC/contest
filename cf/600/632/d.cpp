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
const int N = 3 + 1e6;

int n, m, a[N];
int f[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] <= m) {
            ++f[a[i]];
        }
    }
    for (int i = m; i >= 1; --i) {
        for (int j = i + i; j <= 1e6; j += i) {
            f[j] += f[i];
        }
    }
    int p = 1;
    for (int i = 1; i <= m; ++i) {
        if (f[p] < f[i]) {
            p = i;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (p % a[i] == 0) {
            ans.push_back(i);
        }
    }
    if (ans.empty()) {
        cout << 1 << ' ' << 0 << endl;
        return 0;
    }
    p = a[ans[0]];
    for (auto &i : ans) {
        p = (LL)p / __gcd(p, a[i]) * a[i];
    }
    cout << p << ' ' << ans.size() << endl;
    for (auto &i : ans) {
        cout << i << ' ';
    }
    return 0;
}