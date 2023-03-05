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
int p[N], q[N];

void solve() {
    set<int> pp;
    set<int> qq;
    for (int i = 1; i <= n; ++i) {
        pp.insert(i);
        qq.insert(i);
        p[i] = q[i] = 0;
    }
    vector<int> id(n + 1);
    for (int i = 1; i <= n; ++i) {
        id[i] = i;
    }
    sort(id.begin() + 1, id.end(), [&](const int &u, const int &v) {
        return a[u] > a[v];
    });
    for (int i = 1; i <= n; ++i) {
        if (pp.count(a[id[i]])) {
            p[id[i]] = a[id[i]];
            pp.erase(a[id[i]]);
        } else if (qq.count(a[id[i]])) {
            q[id[i]] = a[id[i]];
            qq.erase(a[id[i]]);
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!p[id[i]]) {
            p[id[i]] = *pp.rbegin();
            pp.erase(prev(pp.end()));
        }
        if (!q[id[i]]) {
            q[id[i]] = *qq.rbegin();
            qq.erase(prev(qq.end()));
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << p[i] << ' ';
    // }
    // cout << endl;
    // for (int i = 1; i <= n; ++i) {
    //     cout << q[i] << ' ';
    // }
    // cout << endl;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != max(p[i], q[i])) {
            db("");
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n; ++i) {
        cout << q[i] << ' ';
    }
    cout << endl;
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