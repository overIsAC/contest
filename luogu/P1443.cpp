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
const int N = 3 + 1111;

int n, m, x, y, d[N][N];

int main() {
    cin >> n >> m >> x >> y;
    memset(d, 0x3f, sizeof(d));
    queue<PII> q;
    d[x][y] = 0;
    q.push({x, y});
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        vector<array<int, 2>> dt = {
            {x + 1, y + 2},
            {x - 1, y + 2},
            {x + 1, y - 2},
            {x - 1, y - 2},
            {x + 2, y + 1},
            {x - 2, y + 1},
            {x + 2, y - 1},
            {x - 2, y - 1},
        };
        for (auto [dx, dy] : dt) {
            if (1 <= dx && dx <= n && 1 <= dy && dy <= m) {
                if (d[dx][dy] > d[x][y] + 1) {
                    d[dx][dy] = d[x][y] + 1;
                    q.push({dx, dy});
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (d[i][j] > 1e9) {
                d[i][j] = -1;
            }
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}