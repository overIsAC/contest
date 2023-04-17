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

int n, m, k;
vector<vector<int>> edge[N];
LL d[N];
int vis[N];
int pre[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w, i});
        edge[v].push_back({u, w, i});
    }
    priority_queue<pair<LL, int>> q;
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    q.push({0, 1});
    vector<int> seq;
    while (q.size()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) {
            continue;
        }
        if (x != 1) {
            seq.push_back(x);
        }
        vis[x] = 1;
        for (auto& e : edge[x]) {
            int y = e[0], w = e[1], id = e[2];
            if (d[y] > d[x] + w) {
                d[y] = d[x] + w;
                q.push({-d[y], y});
                pre[y] = id;
            }
        }
    }
    while (seq.size() > k) {
        seq.pop_back();
    }
    cout << seq.size() << endl;
    for (auto& i : seq) {
        cout << pre[i] << ' ';
    }
    return 0;
}