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
    int n, k;
    cin >> n >> k;
    vector<int> ans(n);

    int u = 1, v = n;
 
    for (int i = 0; i < k; i += 2) {
        for (int j = i; j < n; j += k) {
            ans[j] = u++;
        }
    }
    for (int i = 1; i < k; i += 2) {
        for (int j = i; j < n; j += k) {
            ans[j] = v--;
        }
    }

    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}