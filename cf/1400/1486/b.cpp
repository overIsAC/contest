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
const int N = 3 + 1e5;

int n, x[N], y[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> x[i] >> y[i];
        }
        sort(x + 1, x + n + 1);
        sort(y + 1, y + n + 1);
        if (n % 2) {
            cout << 1 << endl;
        } else {
            int m = n / 2;
            cout << (LL)(x[m + 1] - x[m] + 1) * (y[m + 1] - y[m] + 1) << endl;
        }
    }
    return 0;
}