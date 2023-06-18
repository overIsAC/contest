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

int n, q, a[N];
map<int, vector<int>> mp;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (y > mp[x].size()) {
            cout << -1 << endl;
        } else {
            cout << mp[x][y - 1] << endl;
        }
    }
    return 0;
}