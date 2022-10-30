#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        int l = 1, r = n;
        while (l < r) {
            while (l < r && a[l] == 0) {
                ++l;
            }
            if (l == r) {
                break;
            }
            while (l < r && a[r] == 1) {
                --r;
            }
            if (l == r) {
                break;
            }
            ++ans;
            ++l;
            --r;
        }
        cout << ans << endl;
    }
    return 0;
}