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
        LL ans = 0;
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
            ans = max(ans, i * (n - 1LL));
        }
        ans = max(ans, (accumulate(a.begin(), a.end(), 0LL) + n - 2) / (n - 1) * (n - 1));
        cout << ans - accumulate(a.begin(), a.end(), 0LL) << endl;
    }
    return 0;
}