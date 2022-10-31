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
vector<int> ve[N];
int inv[N];

void solve() {
    map<int, int> id;
    auto get = [&](int v) {
        if (!id[v]) {
            id[v] = id.size();
            inv[id.size()] = v;
            ve[id.size()].clear();
        }
        v = id[v];
        return v;
    };

    for (int i = 1; i <= n; ++i) {
        a[i] = get(a[i]);
        ve[a[i]].push_back(i);
    }

    int ans = inv[1];
    int l = 1, r = 1;
    int last = 1, sum, now = 1;
    for (int i = 1; i <= id.size(); ++i) {
        last = ve[i][0];
        sum = 1;
        for (int j = 1; j < ve[i].size(); ++j) {
            sum = sum - (ve[i][j] - ve[i][j - 1] - 1) + 1;
            if (sum <= 0) {
                sum = 1;
                last = ve[i][j];
            }
            if (sum > now) {
                now = sum;
                l = last;
                r = ve[i][j];
                ans = inv[i];
            }
        }
    }
    cout << ans << ' ' << l << ' ' << r << endl;
}

int main() {
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