#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N], p[N];

int calc() {
    int ans = 0;
    int l = n, r = 1;
    for (int i = 1; i <= n; ++i) {
        l = min(l, p[i]);
        r = max(r, p[i]);
        if (r - l + 1 == i) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            p[a[i]] = i;
        }
        int u = 1, v = 1, d = calc();
        int x = 1, y = a[1];
        swap(a[p[x]], a[p[y]]);
        swap(p[x], p[y]);
        if (d> calc()) {
            d = calc();
            u = p[x];
            v = p[y];
        }
        swap(p[x], p[y]);
        swap(a[p[x]], a[p[y]]);

        x = 1;
        y = a[n];
        swap(a[p[x]], a[p[y]]);
        swap(p[x], p[y]);
        if (d> calc()) {
            d = calc();
            u = p[x];
            v = p[y];
        }
        swap(p[x], p[y]);
        swap(a[p[x]], a[p[y]]);

        x = 2;
        y = a[1];
        swap(a[p[x]], a[p[y]]);
        swap(p[x], p[y]);
        if (d> calc()) {
            d = calc();
            u = p[x];
            v = p[y];
        }
        swap(p[x], p[y]);
        swap(a[p[x]], a[p[y]]);

        x = 2;
        y = a[n];
        swap(a[p[x]], a[p[y]]);
        swap(p[x], p[y]);
        if (d> calc()) {
            d = calc();
            u = p[x];
            v = p[y];
        }
        swap(p[x], p[y]);
        swap(a[p[x]], a[p[y]]);

        cout << u << ' ' << v << endl;
    }
    return 0;
}