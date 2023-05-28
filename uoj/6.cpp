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
const int N = 3 + 5000;

int n, m, q;
int t[N * N], a, b, c, d;
short x[N * N], y[N * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t[0] >> a >> b >> c >> d;
    cin >> n >> m >> q;
    for (int i = 1; i <= n * m; ++i) {
        t[i] = ((LL)a * t[i - 1] % d * t[i - 1] + (LL)b * t[i - 1] + c) % d;
    }
    for (int i = 1; i <= n * m; ++i) {
        int p = t[i];
        t[i] = i;
        swap(t[i], t[p % i + 1]);
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        swap(t[u], t[v]);
    }
    for (int i = 1; i <= n * m; ++i) {
        x[t[i]] = (i - 1) / m + 1;
        y[t[i]] = (i - 1) % m + 1;
    }

    set<PII> st;
    st.insert({0, 0});
    st.insert({n + 1, m + 1});
    for (int i = 1; i <= n * m; ++i) {
        auto p = st.upper_bound({x[i], y[i]});
        if (p->second < y[i]) {
            continue;
        }
        --p;
        if (p->second > y[i]) {
            continue;
        }
        st.insert({x[i], y[i]});
    }
    st.erase({0, 0});
    st.erase({n + 1, m + 1});
    vector<int> ans;
    for (auto [x, y] : st) {
        ans.push_back(t[(x - 1) * m + y]);
    }
    sort(ans.begin(), ans.end());
    for (auto &i : ans) {
        cout << i << ' ';
    }

    return 0;
}