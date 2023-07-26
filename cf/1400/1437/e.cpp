#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 5e5;

int n, m, a[N], b[N];
int vis[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] -= i - 1;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    for (int i = 2; i <= m; ++i) {
        if (a[b[i - 1]] > a[b[i]]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 1; i <= m; ++i) {
        vis[b[i]] = 1;
    }
    a[0] = -2e9;
    a[n + 1] = 2e9;
    vis[0] = 1;
    vis[n + 1] = 1;

    int ans = 0;

    auto calc = [&](vector<int> a) -> int {
        if (a.empty()) {
            return 0;
        }
        vector<int> b;
        for (auto &i : a) {
            if (b.empty() || b.back() <= i) {
                b.push_back(i);
            } else {
                *upper_bound(b.begin(), b.end(), i) = i;
            }
        }
        return b.size();
    };

    for (int i = 0; i <= n; ++i) {
        int j = i + 1;
        while (!vis[j]) {
            ++j;
        }
        if (i + 1 == j) {
            continue;
        }
        vector<int> b;
        for (int k = i + 1; k <= j - 1; ++k) {
            if (a[i] <= a[k] && a[k] <= a[j]) {
                b.push_back(a[k]);
            }
        }
        ans += calc(b);
        i = j - 1;
    }

    ans = n - m - ans;

    cout << ans << endl;

    return 0;
}