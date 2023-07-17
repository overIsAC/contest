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
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        vector ve(k + 1, vector<int>());
        for (int i = 0; i < n; ++i) {
            ve[a[i]].push_back(i + 1);
        }
        int ans = 1e9;
        for (int i = 1; i <= k; ++i) {
            auto &u = ve[i];
            if (u.empty()) {
                continue;
            }
            vector<int> v;
            v.push_back(u[0] - 1);
            for (int i = 1; i < u.size(); ++i) {
                v.push_back(u[i] - u[i - 1] - 1);
            }
            v.push_back(n - u.back());
            sort(v.begin(), v.end());
            int c = v.back();
            v.pop_back();
            v.push_back(c / 2);
            sort(v.begin(), v.end());
            ans = min(ans, v.back());
        }
        cout << ans << endl;
    }
    return 0;
}