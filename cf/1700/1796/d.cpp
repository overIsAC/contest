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

int n, k, x, a[N];

struct TreeNode {
    LL sum[21], max[21], lmax[21], rmax[21];
} node[530000];

void up(int k, int lsz, int rsz) {
    auto &ans = node[k];
    const auto &l = node[lson];
    const auto &r = node[rson];

    for (int i = 0; i <= ::k; ++i) {
        if (i > lsz) {
            continue;
        }
        for (int j = 0; i + j <= ::k; ++j) {
            if (j > rsz) {
                continue;
            }
            ans.sum[i + j] = max(ans.sum[i + j], l.sum[i] + r.sum[j]);
            ans.max[i + j] = max({ans.max[i + j], l.max[i], r.max[j], l.rmax[i] + r.lmax[j]});
            ans.lmax[i + j] = max({ans.lmax[i + j], l.lmax[i], l.sum[i] + r.lmax[j]});
            ans.rmax[i + j] = max({ans.rmax[i + j], r.rmax[j], l.rmax[i] + r.sum[j]});
        }
    }
}
void build(int k, int l, int r) {
    for (int i = 0; i <= ::k; ++i) {
        node[k].lmax[i] = node[k].rmax[i] = node[k].sum[i] = node[k].max[i] = -1e18;
    }
    if (l == r) {
        node[k].lmax[0] = node[k].rmax[0] = node[k].sum[0] = node[k].max[0] = a[r] - x;
        node[k].lmax[1] = node[k].rmax[1] = node[k].sum[1] = node[k].max[1] = a[r] + x;
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    up(k, mid-l + 1, r -mid);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k >> x;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        build(1, 1, n);
        cout << max(node[1].max[k], 0LL) << endl;
    }
    return 0;
}