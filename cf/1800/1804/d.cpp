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
const int N = 3 + 5e5;

int n, m;
int dp[N];

void solve(vector<vector<int>> &a) {
    int mn = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        int temp = accumulate(a[i].begin(), a[i].end(), 0);
        int cnt = temp;
        int v = m / 4;
        for (int j = 1; j < m; ++j) {
            if (a[i][j] && a[i][j - 1] && !flag && v > 0) {
                flag = true;
                --cnt;
                --v;
            } else {
                flag = false;
            }
        }
        mn += cnt;
        ///////////////////////////////////////////////////
        ///////////////////////////////////////////////////
        ///////////////////////////////////////////////////
        v = m / 4;
        int u = m / 2;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0) {
            } else {
                ++mx;
                if (j + 1 < m) {
                    if (a[i][j + 1]) {
                        if (j >= 1  && a[i][j - 1] == 0 && v > 0) {
                            --v;
                        } else if (u > 0) {
                            --u;
                        } else {
                            assert(v);
                            ++j;
                            --v;
                        }
                    }
                }
            }
            // cout << j << ' ' << u << ' ' << v << endl;
        }
    }
    cout << mn << ' ' << mx << endl;
}

int main() {
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &i : a) {
        for (auto &j : i) {
            scanf("%1d", &j);
        }
    }
    solve(a);
    return 0;
}