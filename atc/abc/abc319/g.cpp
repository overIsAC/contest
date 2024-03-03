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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 2e5;

vector<int> banEdge[N];
int n, m;
int cnt[N];

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        banEdge[u].push_back(v);
        banEdge[v].push_back(u);
    }
    set<int> st;
    for (int i = 2; i <= n; ++i) {
        st.insert(i);
    }
    set<int> u;
    u.insert(1);
    cnt[1] = 1;
    while (u.size()) {
        LL sum = 0;
        map<int, int> mp;
        set<int> v;

        for (int i : u) {
            sum = (sum + cnt[i]) % mod;
            for (auto& j : banEdge[i]) {
                ++mp[j];
            }
        }
        for (auto& i : st) {
            if (mp[i] < u.size()) {
                v.insert(i);
            }
        }
        for (auto& i : v) {
            cnt[i] = sum;
            st.erase(i);
        }
        for (auto& i : u) {
            for (auto& j : banEdge[i]) {
                if (v.count(j)) {
                    cnt[j] = (cnt[j] - cnt[i]) % mod;
                }
            }
        }

        swap(u, v);
    }

    if (st.count(n)) {
        cout << -1 << endl;
        return 0;
    }
    int ans = cnt[n];
    ans = (ans % mod + mod) % mod;
    cout << ans << endl;

    return 0;
}