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
const int N = 3 + 1e6;

int n, m;
bool sq[N];

vector<int> dx, dy;
vector<PII> ve;
int d[420][420];

int main() {
    for (int i = 1; i * i <= 1e6; ++i) {
        sq[i * i] = true;
    }
    cin >> n >> m;
    for (int i = 0; i * i <= m; ++i) {
        if (i * i <= m - i * i && sq[m - i * i]) {
            ve.push_back({i, int(sqrt(m - i * i))});
            ve.push_back({-i, int(sqrt(m - i * i))});
            ve.push_back({i, -int(sqrt(m - i * i))});
            ve.push_back({-i, -int(sqrt(m - i * i))});
            ve.push_back({int(sqrt(m - i * i)), i});
            ve.push_back({-int(sqrt(m - i * i)), i});
            ve.push_back({int(sqrt(m - i * i)), -i});
            ve.push_back({-int(sqrt(m - i * i)), -i});
        }
    }
    queue<PII> q;
    q.push({1, 1});
    memset(d, 0x3f, sizeof(d));
    d[1][1] = 0;
    while (q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (auto p : ve) {
            int tx = p.first + x, ty = p.second + y;
            if (0 < tx && tx <= n && 0 < ty && ty <= n) {
                if (d[tx][ty] > d[x][y] + 1) {
                    d[tx][ty] = d[x][y] + 1;
                    q.push({tx, ty});
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int v = d[i][j];
            if (v >= n * n * 10) {
                v = -1;
            }
            cout << v << ' ';
        }
        cout << endl;
    }
    return 0;
}