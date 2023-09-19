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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (auto &i : a) {
            cin >> i;
        }
        for (auto &i : b) {
            cin >> i;
        }
        vector<int> c(n);
        int mx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            c[i] = a[i] - b[i];
            mx = max(mx, c[i]);
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (c[i] == mx) {
                ans.push_back(i + 1);
            }
        }
        cout << ans.size() << endl;
        for (auto &i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}