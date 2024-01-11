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

int n, a[N];
LL pre[N][2];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    pre[1][1] = a[1];
    for (int i = 2; i <= n; ++i) {
        pre[i][0] = pre[i - 2][0];
        pre[i][1] = pre[i - 2][1];
        pre[i][i % 2] += a[i];
    }

    for (int i = 2; i <= n; ++i) {
        if (a[i] == a[i - 1]) {
            cout << "YES" << endl;
            return;
        }
    }
    set<LL> st;
    st.insert(-a[1]);
    st.insert(0);
    for (int i = 2; i <= n; ++i) {
        LL d;
        if (i % 2 == 0) {
            d = pre[i][0] - pre[i - 1][1];
        } else {
            d = pre[i - 1][0] - pre[i][1];
        }
        if (st.count(d)) {
            cout << "YES" << endl;
            return;
        }
        if (i % 2 == 0) {
            st.insert(pre[i][0] - pre[i - 1][1]);
        } else {
            st.insert(pre[i - 1][0] - pre[i][1]);
        }
    }
    cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}