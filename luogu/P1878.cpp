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
const int N = 3 + 2e5;

int n;
char s[N];
int a[N];
set<int> st;
set<array<int, 3>> z;

int main() {
    cin >> n;
    cin >> s + 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        st.insert(i);
    }

    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i + 1]) {
            z.insert({abs(a[i] - a[i + 1]), i, i + 1});
        }
    }

    vector<vector<int>> ans;

    auto insert = [&](int idx) {
        auto u = st.lower_bound(idx);
        if (u != st.end() && u != st.begin()) {
            auto v = u;
            --u;
            if (s[*u] != s[*v]) {
                z.insert({abs(a[*u] - a[*v]), *u, *v});
            }
        }
    };

    while (z.size()) {
        auto [x, i, j] = *z.begin();
        z.erase(z.begin());
        if (!st.count(i) || !st.count(j)) {
            continue;
        }
        st.erase(i);
        st.erase(j);
        ans.push_back({i, j});
        insert(i);
        insert(j);
    }

    cout << ans.size() << endl;
    for (auto& i : ans) {
        sort(i.begin(), i.end());
        cout << i[0] << ' ' << i[1] << endl;
    }
    return 0;
}