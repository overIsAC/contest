#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 1e5;

LL c[N], pre[N];
int n, m, t, a[N], b[N];

LL calc(int *a, int n) {
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    if (pre[n] % n) {
        return -1;
    }
    for (int i = 1; i <= n; ++i) {
        c[i] = pre[i] - pre[n] / n * i;
    }
    sort(c + 1, c + n + 1);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += abs(c[i] - c[(n + 1) / 2]);
    }
    return ans;
}

int main() {
    cin >> n >> m >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        ++a[x];
        ++b[y];
    }
    LL u = calc(a, n), v = calc(b, m);
    if (u == -1 && v == -1) {
        cout << "impossible" << endl;
    } else if (u == -1) {
        cout << "column " << v << endl;
    } else if (v == -1) {
        cout << "row " << u << endl;
    } else {
        cout << "both " << u + v << endl;
    }
    return 0;
}          