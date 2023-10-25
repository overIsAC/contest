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
const int N = 3 + 20;

int n, m, a[N];
int c[N][N];
int vis[N];
vector<int> stk;

int dfs(int p, int sum) {
    if (sum > m) {
        return 0;
    }
    if (p == n + 1) {
        if (sum == m) {
            for (auto &i : stk) {
                cout << i << ' ';
            }
            return 1;
        }
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            continue;
        }
        vis[i] = 1;
        stk.push_back(i);
        if (dfs(p + 1, sum + c[n - 1][p - 1] * i)) {
            return 1;
        }
        stk.pop_back();
        vis[i] = 0;
    }
    return 0; 
}

int main() {
    cin >> n >> m;
    c[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    dfs(1, 0);
    return 0;
}