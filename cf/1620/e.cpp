#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 5e5;

int fa[N], val[N];
int n;
map<int, int> mp;

int find(int p) { return p == fa[p] ? p : fa[p] = find(fa[p]); }

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    int op, x, y;
    int m = 0;
    while (n--) {
        cin >> op >> x;
        if (op == 1) {
            ++m;
            if (mp[x])
                fa[m] = mp[x];
            else {
                mp[x] = m;
                val[m] = x;
            }
        } else {
            cin >> y;
            if (!mp[x]) continue;
            if (!mp[y]) {
                val[mp[x]] = y;
                mp[y] = mp[x] ;
                mp[x] = 0;
                continue;
            }
            int u = find(mp[x]), v = find(mp[y]);
            if (u == v) continue;
            fa[u] = v;
            mp[x] = 0;
        }
        // cout << endl;
        // for (int i = 1; i <= m; ++i) {
        //     cout << val[find(i)] << ' ';
        // }
        // cout << endl;
    }
    for (int i = 1; i <= m; ++i) {
        cout << val[find(i)] << ' ';
    }
    return 0;
}