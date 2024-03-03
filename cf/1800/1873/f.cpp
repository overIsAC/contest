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
        vector<int> a(n), b(n);
        for (auto& i : a) {
            cin >> i;
        }
        for (auto& i : b) {
            cin >> i;
        }
        LL sum = 0;
        int ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (j < i && b[i - 1] % b[i]) {
                j = i;
                sum = a[i];
            } else {
                sum += a[i];
            }

            while (j <= i && sum > k) {
                sum -= a[j];
                ++j;
            }
            ans = max(ans, i - j + 1);
        }
        cout << ans << endl;
    }

    return 0;
}