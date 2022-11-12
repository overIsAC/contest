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

int tr1[N], tr2[N];
int n, m;

void add(int *tr, int p, int v) {
    for (; p <= n; p += p & -p) {
        tr[p] += v;
    }
}

int ask(int *tr, int p) {
    int ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1, l, r, q; i <= m; ++i) {
        cin >> q >> l >> r;
        if (q == 1) {
            add(tr1, l, 1);
            add(tr2, r + 1, 1);
        } else {
            cout << ask(tr1, r) - ask(tr2, l) << endl;
        }
    }

    return 0;
}