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
        for (auto &i : a) {
            cin >> i;
        }
        sort(a.begin(), a.end());
        auto valid = [&](int k) {
            int i = 0, j = n - 1;
            int c = 1;
            db(k);
            while (true) {
                while (i <= j && k - c + 1 < a[j]) {
                    --j;
                }
                if (i > j) {
                    return false;
                }
                ++c;
                if (c == k + 1) {
                    return true;
                }
                --j;
                ++i;
                if (i > j) {
                    return false;
                }
            }
            return true;
        };
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (valid(i)) {
                ans = max(ans, i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}