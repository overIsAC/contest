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
const int N = 3 + 1e5;

LL x, y;

void solve() {
    LL g = __gcd(x, y);
    LL xx = x / g, yy = y / g;
    string sx = to_string(x);
    string sy = to_string(y);
    map<char, int> mx, my;
    for (char i = '0'; i <= '9'; ++i) {
        mx[i] = 0;
        my[i] = 0;
    }
    for (auto &i : sx) {
        ++mx[i];
    }
    for (auto &i : sy) {
        ++my[i];
    }
    LL ansx = x, ansy = y;
    function<void(int, LL)> dfs = [&](int p, LL nowx) {
        if (nowx >= ansx) {
            return;
        }
        if (p == sx.size()) {
            if (!nowx || nowx % xx) {
                return;
            }
            LL nowy = nowx / xx * yy;
            string nx = to_string(nowx);
            string ny = to_string(nowy);
            int i = 0, j = 0;
            while (i < sy.size() && j < ny.size()) {
                if (sy[i] == ny[j]) {
                    ++i;
                    ++j;
                } else {
                    ++i;
                }
            }
            auto mmx = mx, mmy = my;
            for (auto &i : nx) {
                --mmx[i];
            }
            for (auto &i : ny) {
                --mmy[i];
            }
            if (mmx == mmy && j == ny.size()) {
                ansx = nowx;
                ansy = nowy;
            }
            return;
        }
        dfs(p + 1, nowx);
        dfs(p + 1, nowx * 10 + sx[p] - '0');
    };
    dfs(0, 0);
    cout << ansx << ' ' << ansy << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        solve();
    }
    return 0;
}