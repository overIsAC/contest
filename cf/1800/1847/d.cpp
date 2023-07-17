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

int n, m, q;
char s[N];
int u[N], v[N];

int tr[N];
int id;

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    cin >> s + 1;
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        st.insert(i);
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto p = st.lower_bound(l);
        while (p != st.end() && *p <= r) {
            u[*p] = ++id;
            v[id] = *p;
            p = st.erase(p);
        }
    }
    int o = id;
    for (auto i : st) {
        u[i] = ++id;
        v[id] = i;
    }
    id = o;
    int z = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '0') {
            add(tr, u[i], 1);
        } else {
            ++z;
        }
    }
    while (q--) {
        int x;
        cin >> x;
        if (s[x] == '1') {
            add(tr, u[x], 1);
            --z;
        } else {
            add(tr, u[x], -1);
            ++z;
        }
        s[x] ^= 1;
        cout << ask(tr, min(id, z)) << endl;
    }

    return 0;
}