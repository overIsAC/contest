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
vector<int> edge[N];
set<int> s[N];
int tag[N];
int ans;

void dfs(int x, int fa) {
    bool ok = true;
    for (int& y : edge[x]) {
        if (y == fa) continue;
        dfs(y, x);
        if (s[y].count(a[x] ^ tag[y])) {
            ok = false;
        }
        if (ok) {
            bool swp = false;
            if (s[x].size() < s[y].size()) {
                swap(s[x], s[y]);
                swap(tag[x], tag[y]);
                swp = true;
            }
            for (auto& i : s[y]) {
                if (s[x].count(i ^ tag[y] ^ tag[x])) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (auto& i : s[y]) {
                    s[x].insert(i ^ tag[y] ^ a[x] ^ tag[x]);
                }
                if (swp) {
                    tag[x] ^= a[x];
                }
            }
        }
        s[y].clear();
    }
    if (!ok) {
        s[x].clear();
        tag[x] = 0;
        ++ans;
    } else {
        s[x].insert(a[x] ^ tag[x]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    printf("%d\n", ans);
    return 0;
}
