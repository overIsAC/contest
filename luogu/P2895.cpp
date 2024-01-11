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
const int N = 5 + 300;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n;
int T[N][N], d[N][N];

int main() {
    memset(T, 0x3f, sizeof(T));
    memset(d, 0x3f, sizeof(d));

    cin >> n;
    while (n--) {
        int x, y, t;
        cin >> x >> y >> t;
        T[x][y] = min(T[x][y], t);
        for (int i = 0; i < 4; ++i) {
            int tx = dx[i] + x, ty = dy[i] + y;
            if (0 <= tx && 0 <= ty) {
                T[tx][ty] = min(T[tx][ty], t);
            }
        }
    }

    if (T[0][0] == 0) {
        cout << -1 << endl;
        return 0;
    }

    queue<PII> q;
    q.push({0, 0});
    d[0][0] = 0;

    int ans = 1e9;

    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (T[x][y] > 1e9) {
            ans = min(ans, d[x][y]);
        }

        for (int i = 0; i < 4; ++i) {
            int tx = dx[i] + x, ty = dy[i] + y;
            if (0 <= tx && tx <= 302 && 0 <= ty && ty <= 302) {
                if (d[x][y] + 1 >= T[tx][ty]) {
                    continue;
                }
                if (d[tx][ty] > d[x][y] + 1) {
                    d[tx][ty] = d[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
    }
    if (ans == 1e9) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}