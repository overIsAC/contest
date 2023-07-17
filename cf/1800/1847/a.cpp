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
const int N = 3 + 500;

int n, k, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<int> b;
        for (int i = 2; i <= n; ++i) {
            b.push_back(abs(a[i] - a[i - 1]));
        }
        int ans = 0;
        k = n - k;
        sort(b.begin(), b.end());
        for (int i = 0; i < k; ++i) {
            ans += b[i];
        }
        cout << ans << endl;
    }
    return 0;
}