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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m;
int a[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; ++j) {
            a[j] = 1;
        }
    }
    int t = 0;
    for (int i = 1; i <= m; ++i) {
        if (!a[i])
            ++t;
    }
    cout << t << endl;
    for (int i = 1; i <= m; ++i) {
        if (!a[i])
            cout << i << ' ';
    }
    return 0;
}