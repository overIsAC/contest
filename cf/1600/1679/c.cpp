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

int n, q;

int tr1[N], tr2[N];
int cnt1[N], cnt2[N];

void add(int *tr, int *cnt, int p, int v) {
    if (!cnt[p]) {
        for (; p <= n; p += p & -p) {
            tr[p] += v;
        }
    }
    cnt[p] += v;
    if (!cnt[p]) {
        for (; p <= n; p += p & -p) {
            tr[p] += v;
        }
    }
}

int ask(int *tr, int p) {
    int ans = 0;
    for (; p > 0; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

int main() {
    cin >> n >> q;
    while (q--) {
        int x, y, x1, y1, x2, y2, op;
        cin >> op;
        if (op == 1) {
            cin >> x1 >> y1;
            add(tr1, cnt1, x1, 1);
            add(tr2, cnt2, y1, 1);
        } else if (op == 2) {
            cin >> x1 >> y1;
            add(tr1, cnt1, x1, -1);
            add(tr2, cnt2, y1, -1);
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            if (ask(tr1, x2) - ask(tr1, x1 - 1) == x2 - x1 + 1 || ask(tr2, y2) - ask(tr2, y1 - 1) == y2 - y1 + 1) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}