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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N], q, x, y;
bool mx[N];
int stk[N], nxt[N], top;

void solve() {
    if (!mx[x]) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    if (x > 2) {
        y -= x - 2;
    }
    if (y <= 0) {
        cout << 0 << endl;
        return;
    }
    if (x >= 2 && y >= 1) {
        --y;
        ++ans;
    }
    db(ans);
    if (nxt[x]) {
        ans += min(y, nxt[x] - x - 1);
    } else {
        ans += y;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        int m = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; ++i) {
            if (m > a[i]) {
                mx[i] = false;
            } else {
                mx[i] = true;
                m = a[i];
            }
            nxt[i] = 0;
        }

        top = 0;

        for (int i = 1; i <= n; ++i) {
            while (top && a[stk[top]] < a[i]) {
                nxt[stk[top]] = i;
                --top;
            }
            stk[++top] = i;
        }

        while (q--) {
            cin >> x >> y;
            solve();
        }
    }
    return 0;
}

// 23123
// 5
// 3 2 1 4 5
// 12331
// 1 1