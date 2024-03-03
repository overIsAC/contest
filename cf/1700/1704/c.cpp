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
    int n, m;
    cin >> n >> m;
    set<int> st;
    vector<int> b(m), a;
    for (auto& i : b) {
        cin >> i;
    }
    sort(b.begin(), b.end());
    for (int i = 1; i < m; ++i) {
        a.push_back(b[i] - b[i - 1] - 1);
    }
    a.push_back(n - b.back() + b[0] - 1);
    sort(a.rbegin(), a.rend());
    int ans = 0;
    int p = 0;
    for (auto& i : a) {
        if (i <= 2 * p) {
            break;
        }
        ans += 1;
        --i;
        if (i <= 2 * p + 1) {
            break;
        }

        ans += i - (2 * p + 1);
        p += 2;
    }
    cout << n - ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}