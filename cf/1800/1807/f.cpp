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
const int N = 3 + 2e5;

const int dx[] = {1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1};

int n, m, sx, sy, ex, ey;
string s;
map<string, int> mp = {
    {"DR", 0},
    {"DL", 1},
    {"UR", 2},
    {"UL", 3},
};

bool in(int l, int r, int v) {
    if (l > r) {
        swap(l, r);
    }
    return l <= v && v <= r;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> sx >> sy >> ex >> ey >> s;
        set<vector<int>> st;

        map<PII, int> ss;
        ss.insert({{1, 1}, 0});
        ss.insert({{1, m}, 1});
        ss.insert({{n, 1}, 2});
        ss.insert({{n, m}, 3});

        int d = mp[s];
        int ans = 0;
        while (true) {
            int t;
            if (d == 0) {
                t = min(n - sx, m - sy);
            } else if (d == 1) {
                t = min(n - sx, sy - 1);
            } else if (d == 2) {
                t = min(sx - 1, m - sy);
            } else {
                t = min(sx - 1, sy - 1);
            }
            int tx = sx + t * dx[d];
            int ty = sy + t * dy[d];
            if ((LL)(tx - ex) * (ey - sy) == (LL)(ty - ey) * (ex - sx) && in(sx, tx, ex) && in(sy, ty, ey)) {
                break;
            }
            ++ans;
            sx = tx;
            sy = ty;
            // cout << sx << ' ' << sy << ' ' << d << endl;
            if (ss.count({sx, sy})) {
                d = ss[{sx, sy}];
            } else {
                if (d == 0) {
                    if (sx == n) {
                        d = 2;
                    } else {
                        d = 1;
                    }
                } else if (d == 1) {
                    if (sx == n) {
                        d = 3;
                    } else {
                        d = 0;
                    }
                } else if (d == 2) {
                    if (sx == 1) {
                        d = 0;
                    } else {
                        d = 3;
                    }
                } else {
                    if (sx == 1) {
                        d = 1;
                    } else {
                        d = 2;
                    }
                }
            }
            // cout << d << endl;
            if (st.count({sx, sy, d})) {
                ans = -1;
                break;
            }
            st.insert({sx, sy, d});
        }
        cout << ans << endl;
    }
    return 0;
}