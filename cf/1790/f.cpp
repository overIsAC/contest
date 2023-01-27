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

int n, c[N];
vector<int> edge[N];
int color[N];
int now;
int ti[N];

void bfs(int x) {
    if (now == 1) {
        return;
    }
    queue<int> q;
    map<int, int> d;
    d[x] = 0;
    q.push(x);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto &y : edge[x]) {
            if (d.count(y)) {
                continue;
            }
            if (color[y]) {
                now = min(now, d[x] + 1);
                return;
            }
            d[y] = d[x] + 1;
            if (ti[y] <= d[y]) {
                continue;
            }
            ti[y] = d[y];
            if (d[y] + 1 < now) {
                q.push(y);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
            color[i] = 0;
            ti[i] = n;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        color[c[1]] = 1;
        now = n - 1;
        bfs(c[1]);
        for (int i = 2; i <= n; ++i) {
            color[c[i]] = 1;
            now = min(now, ti[c[i]]);
            bfs(c[i]);
            cout << now << ' ';
        }
        cout << endl;
    }
    return 0;
}