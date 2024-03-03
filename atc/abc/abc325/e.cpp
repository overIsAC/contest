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
const int N = 3 + 1e3;

int n, a, b, c, w[N][N];
LL d[N][2];
int vis[N];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> c;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> w[i][j];
        }
    }
    memset(d, 0x3f, sizeof(d));
    q.push(1);
    d[1][0] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int y = 1; y <= n; ++y) {
            if (d[y][0] > d[x][0] + (LL)w[x][y] * a) {
                d[y][0] = d[x][0] + (LL)w[x][y] * a;
                if (!vis[y]) {
                    vis[y] = 1;
                    q.push(y);
                }
            }
            if (d[y][1] > d[x][0] + (LL)w[x][y] * b + c) {
                d[y][1] = d[x][0] + (LL)w[x][y] * b + c;
                if (!vis[y]) {
                    vis[y] = 1;
                    q.push(y);
                }
            }
            if (d[y][1] > d[x][1] + (LL)w[x][y] * b + c) {
                d[y][1] = d[x][1] + (LL)w[x][y] * b + c;
                if (!vis[y]) {
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
    }
    cout << min(d[n][0], d[n][1]) << endl;

    return 0;
}