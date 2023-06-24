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
const int N = 3 + 111;

int n, m, a[N], b[N];
int hpa[N], hpb[N];
double ans[3];

void dfs(int pa, int pb, int f, int n, int m, double p) {
    if (!n && !m) {
        ans[2] += p;
        return;
    }
    if (!n) {
        ans[1] += p;
        return;
    }
    if (!m) {
        ans[0] += p;
        return;
    }
    if (p < 1e-12) {
        return;
    }
    pa %= ::n;
    pb %= ::m;
    while (!hpa[pa]) {
        pa = (pa + 1) % ::n;
    }
    while (!hpb[pb]) {
        pb = (pb + 1) % ::m;
    }
    if (!f) {
        for (int i = 0; i < ::m; ++i) {
            if (!hpb[i]) {
                continue;
            }
            int u = hpa[pa], v = hpb[i];
            hpa[pa] = max(0, hpa[pa] - b[i]);
            hpb[i] = max(0, hpb[i] - a[pa]);
            dfs(pa + 1, pb, 1, n - (hpa[pa] == 0), m - (hpb[i] == 0), p / m);
            hpa[pa] = u;
            hpb[i] = v;
        }
    } else {
        for (int i = 0; i < ::n; ++i) {
            if (!hpa[i]) {
                continue;
            }
            int u = hpa[i], v = hpb[pb];
            hpa[i] = max(0, hpa[i] - b[pb]);
            hpb[pb] = max(0, hpb[pb] - a[i]);
            dfs(pa, pb + 1, 0, n - (hpa[i] == 0), m - (hpb[pb] == 0), p / n);
            hpa[i] = u;
            hpb[pb] = v;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        hpa[i] = a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        hpb[i] = b[i];
    }
    if (n > m) {
        dfs(0, 0, 0, n, m, 1);
    } else if (n < m) {
        dfs(0, 0, 1, n, m, 1);
    } else {
        dfs(0, 0, 0, n, m, 0.5);
        dfs(0, 0, 1, n, m, 0.5);
    }

    for (auto &i : ans) {
        cout << fixed << setprecision(12) << i << endl;
    }
    return 0;
}