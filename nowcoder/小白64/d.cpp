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
const int N = 3 + 3e5;

int n, a[N];
vector<int> edge[N];
int sz[N];

void dfs(int x) {
    sz[x] = 1;
    for (int &y : edge[x]) {
        dfs(y);
        sz[x] += sz[y];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        int u;
        cin >> u;
        int v = i;
        edge[u].push_back(v);
    }
    dfs(1);
    sort(sz + 1, sz + n + 1);
    sort(a + 1, a + n + 1);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (LL)a[i] * sz[i];
    }
    cout << ans << endl;
    return 0;
}