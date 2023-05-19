#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 1e4;
const int M = 3 + 1e6;

struct Node {
    int l, r, v;
    bool operator < (const Node &other) const {
        return r < other.r;
    }
} a[N];

int n, m, k;
LL tr[M];

int main() {
    cin >> n >> m >> k;
    for (int i= 1; i <= n; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].v;
        a[i].l = a[i].l - m + 1;
        a[i].r = a[i].r - m + 1;
    }
    m = k - m + 1;
    sort(a + 1, a + n + 1);
    memset(tr, 0x3f, sizeof(tr));
    
    tr[1] = 0;
    
    for (int i = 1; i <= n; ++i) {
        LL ans = 1e18;
        for (int j = a[i].l; j <= m + 1; j += j & -j) {
            ans = min(ans, tr[j]);
        }
        for (int j = a[i].r + 1; j >= 1; j -= j & -j) {
            tr[j] = min(tr[j], ans + a[i].v);
        }
    }
    
    LL ans = tr[m + 1];
    if (ans > 1e17) {
        ans = -1;
    }
    cout << ans << endl;
    
    return 0;
}