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

int n, a[N];
LL pow2[N];

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    pow2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pow2[i] = pow2[i - 1] * 2 % mod;
    }
    LL ans = pow2[n] - 1 - n;
    // cout << ans << endl;
    for (int i = 2; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dif = a[j] - a[i];

            if (a[i] - a[i - 1] > dif) {
                continue;
            }
            if (a[j + 1] - a[j] >= dif) {
                continue;
            }

            int L = 1, R = i - 1;

            while (L < R) {
                int mid = L + R >> 1;
                if (a[i] - a[mid] <= dif) {
                    R = mid;
                } else {
                    L = mid + 1;
                }
            }
            int left = R;

            L = j + 1;
            R = n;
            while (L < R) {
                int mid = L + R + 1 >> 1;
                if (a[mid] - a[j] < dif) {
                    L = mid;
                } else {
                    R = mid - 1;
                }
            }
            int right = R;
            // cout << i << ' ' << j << ' ' << left << ' ' << right << endl;
            ans += pow2[left - 1 + n - right] * (pow2[i - left] - 1) % mod * (pow2[right - j] - 1) % mod;
        }
    }
    cout << (ans % mod + mod) % mod << endl;
    return 0;
}