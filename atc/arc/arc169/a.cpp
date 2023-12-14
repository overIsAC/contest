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
const int N = 3 + 250000;

vector<int> edge[N];
int n, a[N];
LL d[N];

void dfs(int x, int fa, int dd) {
    d[dd] += a[x];
    for (auto& y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x, dd + 1);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        int u, v = i;
        cin >> u;
        edge[u].push_back(v);
    }
    dfs(1, 0, 1);
    LL cnt = 0, z = 0;
    for (int i = n; i >= 1; --i) {
        z += d[i];
        cnt += z;
        d[i] += cnt;
        if (d[i]) {
            if (d[i] < 0) {
                cout << "-";
            } else {
                cout << "+";
            }
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}