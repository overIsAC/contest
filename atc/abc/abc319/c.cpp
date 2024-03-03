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
const int N = 3 + 1e5;

int a[10][10];
double ans;
int vis[10][10];
map<int, map<int, int>> x, y, u, v;
map<int, int> sx, sy, su, sv;

int valid() {
    for (auto& i : x) {
        if (sx[i.first] != 2) {
            continue;
        }
        for (auto& j : i.second) {
            if (j.second == 2) {
                return 0;
            }
        }
    }
    for (auto& i : y) {
        if (sy[i.first] != 2) {
            continue;
        }
        for (auto& j : i.second) {
            if (j.second == 2) {
                return 0;
            }
        }
    }
    for (auto& j : u[0]) {
        if (su[0] != 2) {
            continue;
        }
        if (j.second == 2) {
            return 0;
        }
    }
    for (auto& j : v[2]) {
        if (sv[2] != 2) {
            continue;
        }
        if (j.second == 2) {
            return 0;
        }
    }
    return 1;
}

void dfs(int cnt, double p) {
    if (cnt == 9) {
        ans += p;
        return;
    }
    if (!valid()) {
        return;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!vis[i][j]) {
                vis[i][j] = 1;
                ++x[i][a[i][j]];
                ++y[j][a[i][j]];
                ++u[i - j][a[i][j]];
                ++v[i + j][a[i][j]];
                ++sx[i];
                ++sy[j];
                ++su[i - j];
                ++sv[i + j];

                dfs(cnt + 1, p / (9 - cnt));

                vis[i][j] = 0;
                --x[i][a[i][j]];
                --y[j][a[i][j]];
                --u[i - j][a[i][j]];
                --v[i + j][a[i][j]];
                --sx[i];
                --sy[j];
                --su[i - j];
                --sv[i + j];
            }
        }
    }
}

int main() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    dfs(0, 1);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}