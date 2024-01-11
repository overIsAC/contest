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
const int N = 3 + 5e5;

int n, q, a[N], b[N];
LL c[N];
LL sum, now;

LL tr[N];
set<int> st;

void add(LL* tr, int p, int v) {
    for (; p <= n; p += p & -p) {
        tr[p] += v;
    }
}

LL ask(LL* tr, int p) {
    LL ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= b[i]) {
            sum += a[i] - b[i];
            st.insert(i);
        } else {
            add(tr, i, b[i] - a[i]);
        }
        now += a[i];
    }
    while (q--) {
        int p, x, y;
        LL z;
        cin >> p >> x >> y >> z;

        if (a[p] >= b[p]) {
            sum -= a[p] - b[p];
            st.erase(p);
        } else {
            add(tr, p, -(b[p] - a[p]));
        }
        now -= a[p];

        a[p] = x;
        b[p] = y;

        if (a[p] >= b[p]) {
            sum += a[p] - b[p];
            st.insert(p);
        } else {
            add(tr, p, (b[p] - a[p]));
        }

        now += a[p];

        LL ans = now;
        ans -= sum;
        if (st.size()) {
            ans += min<LL>(ask(tr, n) - ask(tr, *st.begin() - 1), sum);
        }
        cout << ans << '\n';
    }

    return 0;
}