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
const int N = 3 + 2e5;

int n;
LL k;
int x[N], y[N];
LL prex[N], prey[N], sufx[N], sufy[N];

int ok(int d) {
    LL cntx = 1e18;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (x[i] - x[j] > d) {
            ++j;
        }
        LL u = (LL)(x[i] - d) * (j - 1) - prex[j - 1];
        LL v = sufx[i] - (LL)x[i] * (n - i + 1);
        cntx = min(cntx, u + v);
    }
    for (int i = n, j = n; j >= 1; --j) {
        while (x[i] - x[j] > d) {
            --i;
        }
        LL u = (LL)x[j] * j - prex[j];
        LL v = sufx[i + 1] - (LL)(x[j] + d) * (n - i);
        cntx = min(cntx, u + v);
    }

    LL cnty = 1e18;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (y[i] - y[j] > d) {
            ++j;
        }
        LL u = (LL)(y[i] - d) * (j - 1) - prey[j - 1];
        LL v = sufy[i] - (LL)y[i] * (n - i + 1);
        cnty = min(cnty, u + v);
    }
    for (int i = n, j = n; j >= 1; --j) {
        while (y[i] - y[j] > d) {
            --i;
        }
        LL u = (LL)y[j] * j - prey[j];
        LL v = sufy[i + 1] - (LL)(y[j] + d) * (n - i);
        cnty = min(cnty, u + v);
    }
    return cntx + cnty <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);

    for (int i = 1; i <= n; ++i) {
        prex[i] = prex[i - 1] + x[i];
        prey[i] = prey[i - 1] + y[i];
    }
    for (int i = n; i >= 1; --i) {
        sufx[i] = sufx[i + 1] + x[i];
        sufy[i] = sufy[i + 1] + y[i];
    }

    int L = 0, R = 1e9;
    while (L < R) {
        int mid = L + R >> 1;
        if (ok(mid)) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << R << endl;

    return 0;
}