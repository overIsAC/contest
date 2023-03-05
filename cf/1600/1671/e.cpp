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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e6;

int n;
char s[N];

int ls[N], rs[N];
int eq[N];
LL ans[N];

int cmp(int x, int y) {
    if (s[x] != s[y]) {
        if (s[x] < s[y]) {
            return -1;
        } else {
            return 1;
        }
    }
    if (ls[x]) {
        int res = cmp(ls[x], ls[y]);
        if (!res) {
            res = cmp(rs[x], rs[y]);
        }
        return res;
    } else {
        return 0;
    }
}

void dfs(int x) {
    ans[x] = 1;
    if (ls[x]) {
        dfs(ls[x]);
        dfs(rs[x]);
        if ((eq[x] = cmp(ls[x], rs[x])) > 0) {
            swap(ls[x], rs[x]);
        }
        ans[x] = ans[ls[x]] * ans[rs[x]] % mod;
        if (eq[x]) {
            ans[x] = ans[x] * 2 % mod;
        }
    }
}

int main() {
    cin >> n;
    cin >> s + 1;
    int m = (1 << n) - 1;
    for (int k = 1; k <= m; ++k) {
        if (lson <= m) {
            ls[k] = lson;
            rs[k] = rson;
        } 
    }
    dfs(1);
    cout << ans[1] << endl;
    return 0;
}