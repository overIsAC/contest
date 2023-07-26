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
// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LL ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (!a[i]) {
            continue;
        }
        int cnt = 0, p = i;
        while (a[p]) {
            ++cnt;
            int pp = a[p];
            a[p] = 0;
            p = pp;
        }
        if (cnt % 2) {
            ans = 0;
        }
        ans = ans * 2 % mod;
    }
    cout << ans << endl;
    return 0;
}