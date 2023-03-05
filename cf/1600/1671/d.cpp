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

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N], x;

void f(int x) {
    if (n <= 1) {
        a[++n] = x;
        return;
    }
    int p = 0;
    LL c = abs<LL>(a[1] - x);
    if (abs(a[n] - x) < c) {
        c = abs(a[n] - x);
        p = n;
    }
    for (int i = 1; i < n; ++i) {
        if (c > abs<LL>(a[i] - x) + abs(x - a[i + 1]) - abs(a[i] - a[i + 1])) {
            c = abs<LL>(a[i] - x) + abs(x - a[i + 1]) - abs(a[i] - a[i + 1]);
            p = i;
        }
    }
    for (int i = n + 1; i - 1 >= p + 1; --i) {
        a[i] = a[i - 1];
    }
    a[p + 1] = x;
    ++n;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        f(1);
        f(x);
        LL ans = 0;
        for (int i = 1; i < n; ++i) {
            ans += abs(a[i] - a[i + 1]);
        }
        cout << ans << endl;
    }
    return 0;
}