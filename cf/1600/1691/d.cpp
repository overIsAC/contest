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
LL pre[N];

void solve() {
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }

    vector<int> ve;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > 0) {
            ve.push_back(i);
        }
    }
    for (int i = 0; i + 1 < ve.size(); ++i) {
        if (pre[ve[i + 1]] - pre[ve[i] - 1] > max(a[ve[i + 1]], a[ve[i]])) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        solve();
    }
    return 0;
}