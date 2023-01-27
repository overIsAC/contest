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
const int N = 3 + (1 << 20);

int n, a[N];
LL u[21], v[21];
int b[N], t;

void dfs(int l, int r, int p) {
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    dfs(l, mid, p + 1);
    dfs(mid + 1, r, p + 1);
    for (int i = l, j = mid + 1; i <= mid && j <= r;) {
        if (a[i] < a[j]) {
            u[p] += r - j + 1;
            ++i;
        } else {
            ++j;
        }
    }
    for (int i = l, j = mid + 1; i <= mid && j <= r;) {
        if (a[i] > a[j]) {
            v[p] += mid - i + 1;
            ++j;
        } else {
            ++i;
        }
    }
    {
        t = 0;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (a[i] < a[j]) {
                b[++t] = a[i];
                ++i;
            } else {
                b[++t] = a[j];
                ++j;
            }
        }
        while (i <= mid) {
            b[++t] = a[i];
            ++i;
        }
        while (j <= r) {
            b[++t] = a[j];
            ++j;
        }
        for (int i = l, j = 1; i <= r; ++i, ++j) {
            a[i] = b[j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= 1 << n; ++i) {
        cin >> a[i];
    }
    dfs(1, 1 << n, 0);
    int q;
    cin >> q;
    while (q--) {
        int x;
        LL ans = 0;
        cin >> x;
        x = n - x;
        for (int i = x; i <= n; ++i) {
            swap(u[i], v[i]);
        }
        for (int i = 0; i <= n; ++i) {
            ans += v[i];
        }
        cout << ans << endl;
    }
    return 0;
}