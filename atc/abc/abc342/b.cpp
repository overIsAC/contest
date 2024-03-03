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

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& i : p) {
        cin >> i;
    }
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[p[i]] = i;
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        int ans = a;
        if (mp[a] > mp[b]) {
            ans = b;
        }
        cout << ans << endl;
    }
    return 0;
}