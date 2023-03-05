#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n;
char a[N], b[N];

void solve() {
    cin >> n;
    cin >> a + 1;
    cin >> b + 1;
    vector<int> q, w;
    for (int i = 1; i <= n; ++i) {
        int j = i;
        while (j + 1 <= n && a[j + 1] == a[i]) ++j;
        q.push_back(j - i + 1);
        i = j;
    }
    for (int i = 1; i <= n; ++i) {
        int j = i;
        while (j + 1 <= n && b[j + 1] == b[i]) ++j;
        w.push_back(j - i + 1); 
        i = j;
    }
    if (q.size() != w.size() || a[1] != b[1]) {
        cout << -1 << endl;
        return;
    }
    LL ans = 0, pre = 0;
    for (int i = 0; i < q.size(); ++i) {
        pre += q[i] - w[i];
        ans += abs(pre);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}