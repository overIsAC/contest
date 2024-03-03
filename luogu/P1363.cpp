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
const int N = 3 + 1555;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
char s[N][N];
int sx, sy;
vector<PII> z[N][N];

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                z[i][j].clear();
            }
        }

        int ok = 0;

        queue<PII> q;
        q.push({sx, sy});
        while (q.size()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int tx = x + dx[i], ty = y + dy[i];
                int rx = (tx % n + n) % n, ry = (ty % m + m) % m;

                if (s[rx][ry] == '#') {
                    continue;
                }

                int have = 0;
                for (auto& p : z[rx][ry]) {
                    if (p != (PII){tx, ty}) {
                        ok = 1;
                        break;
                    } else {
                        have = 1;
                    }
                }

                if (ok) {
                    break;
                }

                if (!have) {
                    z[rx][ry].push_back({tx, ty});
                    q.push({tx, ty});
                }
            }
            if (ok) {
                break;
            }
        }

        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}