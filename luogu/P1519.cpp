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
const int N = 3 + 500;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
string s[N];

int main() {
    cin >> m >> n;
    cin.get();
    n = 2 * n + 1;
    m = 2 * m + 1;
    for (int i = 0; i < n; ++i) {
        getline(cin, s[i]);
    }
    for (int i = 0; i < n; ++i) {
        cout << s[i] << endl;
    }
    vector d(n, vector<int>(m, 1e9));
    queue<PII> q;
    for (int i = 0; i < n; ++i) {
        if (s[i][0] == ' ') {
            d[i][0] = 0;
            q.push({i, 0});
        }
        if (s[i][m - 1] == ' ') {
            d[i][m - 1] = 0;
            q.push({i, m - 1});
        }
    }
    for (int i = 0; i < m; ++i) {
        if (s[0][i] == ' ') {
            d[0][i] = 0;
            q.push({0, i});
        }
        if (s[n - 1][i] == ' ') {
            d[n - 1][i] = 0;
            q.push({n - 1, i});
        }
    }

    auto valid = [&](int x, int y) {
        if (0 <= x && x < n && 0 <= y && y < m) {
            return s[x][y] == ' ';
        }
        return false;
    };

    int ans = 0;


    scanf("%d")
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        ans = max(ans, d[x][y]);
        for (int i = 0; i < 4; ++i) {
            int tx = dx[i] + x, ty = dy[i] + y;
            if (valid(tx, ty)) {
                if (d[tx][ty] > d[x][y] + 1) {
                    q.push({tx, ty});
                    d[tx][ty] = d[x][y] + 1;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[i][j] == 1e9) {
                cout << -1 << ' ';
            } else {
                cout << d[i][j] << ' ';
            }
        }
        cout << endl;
    }
    cout << ans << endl;

    return 0;
}