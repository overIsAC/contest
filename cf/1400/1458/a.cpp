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

int n, m;
LL a[N], b[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    LL g = 0;
    for (int i = 2; i <= n; ++i) {
        g = gcd(g, a[i] - a[i - 1]);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        cout << gcd(g, b[i] + a[1]) << ' ';
    }
    return 0;
}