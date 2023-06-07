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

int n;
PII a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        map<int, vector<int>> mp;
        for (int i = 1; i <= n; ++i) {
            int a, b;
            cin >> a >> b;
            mp[a].push_back(b);
        }
        LL ans = 0;
        for (auto& [x, y] : mp) {
            sort(y.rbegin(), y.rend());
            for (int i = 1; i <= x && i <= y.size(); ++i) {
                ans += y[i - 1];
            }
        }

        cout << ans << endl;
    }
    return 0;
}