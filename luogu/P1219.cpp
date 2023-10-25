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
const int N = 3 + 111;

vector<vector<int>> ans;
vector<int> stk;
int vis[N];
int n;
int a[N], b[N];

void dfs(int p) {
    if (p == n + 1) {
        ans.push_back(stk);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] || a[p + i] || b[p - i + n]) {
            continue;
        }
        vis[i] = 1;
        a[p + i] = 1;
        b[p - i + n] = 1;
        stk.push_back(i);
        dfs(p + 1);
        stk.pop_back();
        vis[i] = 0;
        a[p + i] = 0;
        b[p - i + n] = 0;
    }
}

int main() {
    cin >> n;
    dfs(1);
    for (int i = 0; i < 3; ++i) {
        for (auto &j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << ans.size() << endl;
    return 0;
}