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
const int N = 3 + 2e3;

int n, b[N], t[N];
int a[N];

int ok(int v) {
    for (int i = 1; i <= n; ++i) {
        a[i] = b[i] - v * t[i];
        if (a[i] < 0) {
            return 0;
        }
    }
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        if (a[i] % (t[i] + t[n - i + 1])) {
            return 0;
        }
        st.insert(a[i] / (t[i] + t[n - i + 1]));
        if (st.size() > 1) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i <= 2000; ++i) {
        if (ok(i)) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}