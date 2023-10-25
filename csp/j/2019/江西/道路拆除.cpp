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
const int N = 3 + 3e3;

int d[N][N];
int n, m, s1, s2, t1, t2;
vector<int> edge[N];

void bfs(int s, int *d) {
    memset(d, 0x3f, sizeof(::d[1]));
    queue<int> q;
    q.push(s);
    d[s] = 0;
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
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    cin >> s1 >> t1 >> s2 >> t2;
    for (int i = 1; i <= n; ++i) {
        bfs(i, d[i]);
    }
    if (d[1][s1] > t1 || d[1][s2] > t2) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[1][i] + d[i][s1] <= t1 && d[1][i] + d[i][s2] <= t2) {
            ans = max(ans, m - (d[1][i] + d[i][s1] + d[i][s2]));
        }
    }
    cout << ans << endl;
    return 0;
}