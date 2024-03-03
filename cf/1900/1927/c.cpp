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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (auto& i : a) {
        cin >> i;
    }
    for (auto& i : b) {
        cin >> i;
    }
    set<int> sa(a.begin(), a.end());
    set<int> sb(b.begin(), b.end());
    int cnta = 0, cntb = 0, cnt = 0;
    for (int i = 1; i <= k; ++i) {
        if (!sa.count(i) && !sb.count(i)) {
            cout << "NO" << endl;
            return;
        }
        if (sa.count(i) && sb.count(i)) {
            ++cnt;
        } else if (sa.count(i)) {
            ++cnta;
        } else {
            ++cntb;
        }
    }
    if (cnta > k / 2 || cntb > k / 2) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}