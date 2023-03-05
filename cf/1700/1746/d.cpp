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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, k;
vector<int> edge[N];
int a[N];
LL ans;

LL dfs(int x, int k) {
    ans += (LL)a[x] * k;
    vector<LL> temp;
    for (int &y : edge[x]) {
        LL v = dfs(y, k / (int)edge[x].size());
        temp.push_back(v);
    }
    sort(temp.rbegin(), temp.rend());
    if (edge[x].size()) {
        int nn = k % (int)temp.size();
        for (int i = 0; i < nn; ++i) {
            ans += temp[i];
        }
        if (nn == 0) {
            return temp[0] + a[x];
        } else {
            return temp[nn] + a[x];
        }
    } else {
        return a[x];
    }
}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u;
            v = i + 1;
            edge[u].push_back(v);
        }
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        ans = 0;
        dfs(1, k);
        cout << ans << endl;
    }
    return 0;
}