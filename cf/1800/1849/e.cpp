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
const int N = 3 + 1e6;

int n, a[N];
int f1[20][N], f2[20][N];
int _lg[N];
LL ans;

int query1(int l, int r) {
    int t = _lg[r - l + 1];
    if (a[f1[t][l]] < a[f1[t][r - (1 << t) + 1]]) {
        return f1[t][l];
    } else {
        return f1[t][r - (1 << t) + 1];
    }
}

int query2(int l, int r) {
    int t = _lg[r - l + 1];
    if (a[f2[t][l]] > a[f2[t][r - (1 << t) + 1]]) {
        return f2[t][l];
    } else {
        return f2[t][r - (1 << t) + 1];
    }
}

void dfs(int l, int r) {
    if (l > r) {
        return;
    }
    int p = query1(l, r);
    dfs(l, p - 1);
    dfs(p + 1, r);
    if (r - p < p - l) {
        int mx = a[p];
        for (int i = p; i <= r; ++i) {
            mx = max(a[i], mx);
            int L = l, R = p;
            while (L < R) {
                int mid = L + R >> 1;
                if (a[query2(mid, p)] <= mx) {
                    R = mid;
                } else {
                    L = mid + 1;
                }
            }
            if (a[query2(R, p)] <= mx) {
                // cout << "RRR " << l << ' ' << r << ' ' << p << ' ' << R << endl;
                ans += p - R + 1;
            }
        }
    } else {
        int mx = a[p];
        for (int i = p; i >= l; --i) {
            mx = max(a[i], mx);
            int L = p, R = r;
            while (L < R) {
                int mid = L + R >> 1;
                if (a[query2(p, mid)] >= mx) {
                    R = mid;
                } else {
                    L = mid + 1;
                }
            }
            if (a[query2(p, R)] >= mx) {
                // cout << "LLL " << l << ' ' << r << ' ' << R << ' ' << r << endl;
                ans += r - R + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        _lg[i] = _lg[i / 2] + 1;
    }
    for (int i = 1; i <= n; ++i) {
        f1[0][i] = f2[0][i] = i;
    }
    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            f1[i][j] = f1[i - 1][j];
            if (a[f1[i][j]] > a[f1[i - 1][j + (1 << i - 1)]]) {
                f1[i][j] = f1[i - 1][j + (1 << i - 1)];
            }
            f2[i][j] = f2[i - 1][j];
            if (a[f2[i][j]] < a[f2[i - 1][j + (1 << i - 1)]]) {
                f2[i][j] = f2[i - 1][j + (1 << i - 1)];
            }
        }
    }

    dfs(1, n);

    cout << ans - n << endl;

    return 0;
}