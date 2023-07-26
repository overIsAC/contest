#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;
const int M = 3 + 1e7;

int a[N], n;
int f[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LL t = 1e18;
    int u, v;
    for (int i = 1; i <= n; ++i) {
        if (f[a[i]]) {
            if (t > a[i]) {
                u = f[a[i]];
                v = i;
                t = a[i];
            }
        }
        f[a[i]] = i;
    }
    for (int i = M - 1; i >= 1; --i) {
        if (i >= t) {
            continue;
        }
        for (int j = i + i; j < M && j < t; j += i) {
            if (f[i] && f[j]) {
                if (f[i] != f[j]) {
                    LL d = (LL)a[f[i]] * a[f[j]] / i;
                    if (t > d) {
                        t = d;
                        u = f[i];
                        v = f[j];
                    }
                }
                if (a[f[i]] > a[f[j]]) {
                    f[i] = f[j];
                }
            }
            if (f[j] && !f[i]) {
                f[i] = f[j];
            }
        }
    }
    if (u > v) {
        swap(u, v);
    }
    cout << u << ' ' << v << endl;
    return 0;
}