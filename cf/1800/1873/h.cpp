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

vector<int> edge[N];
int n, du[N], d1[N], d2[N];
int a, b;

void solve() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        edge[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        du[i] = edge[i].size();
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (du[i] == 1) {
            q.push(i);
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto& y : edge[x]) {
            if (--du[y] == 1) {
                q.push(y);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        d1[i] = 1e9;
        d2[i] = 1e9;
    }
    q.push(a);
    d1[a] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto& y : edge[x]) {
            if (d1[y] > d1[x] + 1) {
                d1[y] = d1[x] + 1;
                q.push(y);
            }
        }
    }
    q.push(b);
    d2[b] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto& y : edge[x]) {
            if (d2[y] > d2[x] + 1) {
                d2[y] = d2[x] + 1;
                if (du[y] != 2) {
                    q.push(y);
                }
            }
        }
    }
    if (a == b) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (du[i] == 2 && d2[i] <= n) {
            if (d1[i] > d2[i]) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}