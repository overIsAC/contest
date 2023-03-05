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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 4e5;

struct Node {
    int u, v;
};

vector<Node> ans;
queue<int> q;
int dd[N];
int du[N];
vector<int> edge[N];
bool ok = true;

void dfs(int x, int fa) {
    dd[x] = dd[fa] + 1;
    for (int& y : edge[x]) {
        if (y == fa)
            continue;
        dfs(y, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d, k;
    cin >> n >> d >> k;

    if (n > 2 and k == 1) {
        cout << "NO" << endl;
        return 0;
    }

    if (n - 1 < d) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 2; i <= d + 1; ++i) {
        ans.push_back({i - 1, i});
        ++du[i - 1];
        ++du[i];
        edge[i - 1].push_back(i);
        edge[i].push_back(i - 1);
    }
    for (int i = 1; i <= d + 1; ++i) {
        dd[i] = max(i - 1, d + 1 - i);
        if (du[i] < k and dd[i] < d) {
            q.push(i);
        }
    }
    for (int i = d + 2; i <= n; ++i) {
        if (q.empty()) {
            cout << "NO" << endl;
            return 0;
        }
        int x = q.front();
        q.pop();
        int y = i;
        ans.push_back({x, y});
        ++du[x];
        ++du[y];
        dd[y] = dd[x] + 1;
        edge[x].push_back(y);
        edge[y].push_back(x);
        if (du[x] < k) {
            q.push(x);
        }
        if (dd[y] < d and du[y] < k) {
            q.push(y);
        }
    }
    if (ans.size() != n - 1) {
        cout << "NO" << endl;
        return 0;
    }
    memset(dd, 0, sizeof(dd));
    dfs(1, 0);
    int p = 1;
    for (int i = 2; i <= n; ++i) {
        if (dd[p] < dd[i]) {
            p = i;
        }
    }
    memset(dd, 0, sizeof(dd));
    dfs(p, 0);
    for (int i = 1; i <= n; ++i) {
        if (dd[i] - 1 > d) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (auto& i : ans) {
        cout << i.u << ' ' << i.v << endl;
    }
    return 0;
}