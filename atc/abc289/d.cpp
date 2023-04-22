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
const int N = 3 + 2e5;

int n, m, a[N], b[N];
int d[N];
int x;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        d[b[i]] = -1;
    }
    d[0] = 0;
    cin >> x;
    for (int i = 0; i <= x; ++i) {
        if (d[i] == -1) {
            continue;
        }
        for (int j = 1; j <= n; ++j) {
            if (d[i + a[j]] > d[i] + 1) {
                d[i + a[j]] = d[i] + 1;
            }
        }
    }
    if (d[x] >= 0 && d[x] < 1e9) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}