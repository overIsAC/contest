#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int inf = 0x3f3f3f3f;
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];
int dp[2][18][36];
int Lg[N];
int t, tt;

struct Node {
    LL x;
    int y;
    bool operator<(const Node &b) const { return x < b.x; }
} b[1000];

struct Node2 {
    int j, k;
    LL a;
    bool operator<(const Node2 &b) const { return a < b.a; }
} c[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Lg[1] = 1;
    for (int i = 2; i < N; ++i) {
        Lg[i] = Lg[i / 2] + 1;
    }

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    memset(dp, 0x3f, sizeof(dp));
    ***dp = 0;
    int p1 = 0, p2 = 1;
    for (int i = 0; i < n; ++i) {
        t = 0;
        for (int j = Lg[a[i]]; j >= 0; --j) {
            for (int k = j; k < 36; ++k) {
                if (dp[p1][j][k] < 18 * n) {
                    ++t;
                    b[t].x = (LL)a[i] >> j << (k - j);
                    b[t].y = dp[p1][j][k];
                }
            }
        }
        tt = 0;
        for (int j = Lg[a[i + 1]]; j >= 0; --j) {
            for (int k = j; k < 36; ++k) {
                ++tt;
                c[tt].a = (LL)a[i + 1] >> j << (k - j);
                c[tt].j = j;
                c[tt].k = k;
            }
        }
        sort(b + 1, b + t + 1);
        sort(c + 1, c + tt + 1);
        int pt1 = 1, pt2 = 1;
        int mn = inf;

        while (pt2 <= tt) {
            while (pt1 <= t && b[pt1].x <= c[pt2].a) {
                mn = min(mn, b[pt1].y);
                ++pt1;
            }
            dp[p2][c[pt2].j][c[pt2].k] = mn + c[pt2].k;
            ++pt2;
        }

        memset(dp[p1], inf, sizeof(dp[p1]));

        p1 ^= 1;
        p2 ^= 1;
    }
    int ans = 1e9;
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 36; ++j) {
            ans = min(ans, dp[n & 1][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
