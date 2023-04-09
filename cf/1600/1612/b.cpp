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

int x, y;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> u, v;
    set<int> st;
    st.insert(a);
    st.insert(b);
    u.push_back(a);
    v.push_back(b);
    for (int i = 1; i <= n; ++i) {
        if (st.count(i)) {
            continue;
        }
        if (i < a) {
            st.insert(i);
            v.push_back(i);
        } else if (i > b) {
            st.insert(i);
            u.push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (st.count(i)) {
            continue;
        }
        if (u.size() != n / 2) {
            u.push_back(i);
        } else if (v.size() != n / 2) {
            v.push_back(i);
        }
    }
    if (u.size() == n / 2 && v.size() == n / 2 && *min_element(u.begin(), u.end()) == a && *max_element(v.begin(), v.end()) == b) {
        for (auto &i : u) {
            cout << i << ' ';
        }
        for (auto &i : v) {
            cout << i << ' ';
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}