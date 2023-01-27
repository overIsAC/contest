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
const int N = 3 + 1e5;

LL tr[N];
int n, m;
LL a[N];
set<int> st;

void add(LL *tr, int p, LL v) {
    for (; p <= n; p += p & -p) {
        tr[p] += v;
    }
}

LL ask(LL *tr, int p) {
    LL ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    while (cin >> n) {
        cout << "Case #" << ++Case << ":\n";
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        st.clear();
        for (int i = 1; i <= n; ++i) {
            st.insert(i);
            tr[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            add(tr, i, a[i]);
        }
        cin >> m;
        while (m--) {
            int op, x, y;
            cin >> op >> x >> y;
            if (x > y) {
                swap(x, y);
            }
            if (op == 0) {
                for (auto p = st.lower_bound(x); p != st.end() && *p <= y;) {
                    add(tr, *p, -a[*p]);
                    LL old = a[*p];
                    a[*p] = sqrtl(a[*p]);
                    add(tr, *p, a[*p]);
                    if (a[*p] == old) {
                        p = st.erase(p);
                    } else {
                        ++p;
                    }
                }
            } else {
                cout << ask(tr, y) - ask(tr, x - 1) << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}