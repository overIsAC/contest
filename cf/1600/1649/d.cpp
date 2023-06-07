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
const int N = 3 + 2e6;

int n, c, a[N];
int pre[N];

void solve() {
    auto get = [&](int p) -> bool {
        return pre[p] - pre[p - 1];
    };
    for (int i = 1; i <= c; ++i) {
        if (!get(i)) {
            continue;
        }
        for (int j = i, k = j + i - 1; j <= c; j += i, k += i) {
            if (pre[k] - pre[j - 1] && !get(j / i)) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> c;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i <= c * 2; ++i) {
            pre[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            pre[a[i]] += 1;
        }
        for (int i = 0; i <= c * 2; ++i) {
            pre[i] += pre[i - 1];
        }
        solve();
    }
    return 0;
}