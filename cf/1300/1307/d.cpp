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
const int N = 3 + 2e5;

int n, m, k;
int a[N];
int d1[N], d2[N];
vector<int> edge[N];

void bfs(int s, int *d) {
    memset(d, 0x3f, sizeof(d1));
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto &y : edge[x]) {
            if (d[y] > d[x] + 1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    bfs(1, d1);
    bfs(n, d2);
    sort(a + 1, a + k + 1, [](int &a, int &b) {
        return d1[a] < d1[b];
    });
    int ans = 0;
    int temp = -1e9;
    for (int i = 1; i <= k; ++i) {
        int u = d2[a[i]] + 1 + temp;
        ans = max(ans, min(u, d1[n]));
        temp = max(temp, d1[a[i]]);
    }
    cout << ans << endl;
    return 0;
}