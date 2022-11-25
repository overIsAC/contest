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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

vector<int> edge[N];
int n;
int ans;

int dfs(int x, int fa) {
    int d = 0;
    for (int& y : edge[x]) {
        if (fa == y) {
            continue;
        }
        d = max(d, dfs(y, x) + 1);
    }
    if (x > 1) {
        if (fa == 1) {
            if (d == 2) {
                ++ans;
            }
        } else {
            if (d == 1) {
                d = 0;
                ++ans;
            }
        }
    }
    return d;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}