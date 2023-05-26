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

int a[N];
int n, m;
int pre[N];

int get(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> a[get(i, j)];
            }
        }

        auto ok = [&](int v) {
            for (int i = 0; i <= n * m; ++i) {
                pre[i] = 0;
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    pre[get(i, j)] = a[get(i, j)] >= v;
                    pre[get(i, j)] += pre[get(i, j - 1)] + pre[get(i - 1, j)] - pre[get(i - 1, j - 1)];
                }
            }
            for (int i = v; i <= n; ++i) {
                for (int j = v; j <= m; ++j) {
                    if (pre[get(i, j)] - pre[get(i, j - v)] - pre[get(i - v, j)] + pre[get(i - v, j - v)] == v * v) {
                        return 1;
                    }
                }
            }
            return 0;
        };

        int l = 1, r = min(n, m);
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (ok(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << r << endl;
    }
    return 0;
}