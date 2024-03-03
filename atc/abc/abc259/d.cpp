#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
const double pi = acos(-1);
// const int mod = 998244353;
const int N = 3 + 3e3;

int fa[N];
int n, x[N], y[N], r[N];

int find(int p) { return p == fa[p] ? p : fa[p] = find(fa[p]); }

int main() {
    int x1, x2, y1, y2;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i] >> r[i];
        for (int j = 1; j < i; ++j) {
            int u = find(i), v = find(j);
            if (v == u) continue;
            LL d = (LL)(x[i] - x[j]) * (x[i] - x[j]) +
                   (LL)(y[i] - y[j]) * (y[i] - y[j]);
            if ((LL)(r[i] - r[j]) * (r[i] - r[j]) <= d &&
                d <= (LL)(r[i] + r[j]) * (r[i] + r[j])) {
                fa[u] = v;
            }
        }
    }
    int p1 = 0, p2 = 0;
    for (int i = 1; i <= n; ++i) {
        if ((LL)(x[i] - x1) * (x[i] - x1) + (LL)(y[i] - y1) * (y[i] - y1) ==
            (LL)r[i] * r[i]) {
            p1 = i;
        }
        if ((LL)(x[i] - x2) * (x[i] - x2) + (LL)(y[i] - y2) * (y[i] - y2) ==
            (LL)r[i] * r[i]) {
            p2 = i;
        }
    }
    if (p1 && p2 && find(p1) == find(p2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}