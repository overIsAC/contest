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
const int N = 3 + 55;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
char s[N][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> s[i] + 1;
        }
        vector<vector<PII>> ve;
        int ok = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i][j] == '.') {
                    continue;
                }
                vector<PII> v;
                queue<PII> q;
                q.push({i, j});
                s[i][j] = '.';
                v.push_back({i, j});
                while (q.size()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int i = 0; i < 4; ++i) {
                        int tx = dx[i] + x, ty = dy[i] + y;
                        if (1 <= tx && tx <= n && 1 <= ty && ty <= m && s[tx][ty] == '*') {
                            q.push({tx, ty});
                            s[tx][ty] = '.';
                            v.push_back({tx, ty});
                        }
                    }
                }

                sort(v.begin(), v.end());

                for (auto [x, y] : v) {
                    for (int dx = -1; dx <= 1; ++dx) {
                        for (int dy = -1; dy <= 1; ++dy) {
                            int tx = dx + x, ty = dy + y;
                            if (1 <= tx && tx <= n && 1 <= ty && ty <= m && s[tx][ty] == '*') {
                                ok = 0;
                            }
                        }
                    }
                }

                ve.push_back(v);
            }
        }
        for (auto& i : ve) {
            if (i.size() != 3) {
                ok = 0;
                break;
            }
            if (i[0].first == i[1].first && i[1].first == i[2].first) {
                ok = 0;
            }
            if (i[0].second == i[1].second && i[1].second == i[2].second) {
                ok = 0;
            }
        }
        if (!ok) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}