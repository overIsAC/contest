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

int n, a[N];
int l[N], r[N];
int pre[N];

int f[N][20], lg[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
    }

    for (int i = 1; i <= n; ++i) {
        if (a[i] >= l[i] && a[i] <= r[i]) {
            ++pre[i];
        }
        pre[i] += pre[i - 1];
    }

    lg[1] = 0;
    for (int i = 2; i <= n; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= n; ++i) {
        f[i][0] = a[i];
    }
    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j + (1 << i - 1) <= n; ++j) {
            if (a[f[j][i - 1]] < a[f[j + (1 << i - 1)][i - 1]]) {
                f[j][i] = f[j + (1 << i - 1)][i - 1];
            } else {
                f[j][i] = f[j][i - 1];
            }
        }
    }

    return 0;
}