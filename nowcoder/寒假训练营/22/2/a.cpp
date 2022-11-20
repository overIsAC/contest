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
const int N = 3 + 2e5;

int n, k;
char s[N];
int prer[N], prep[N];

int main() {
    cin >> n >> k;
    cin >> s + 1;
    for (int i = 1; i <= n; ++i) {
        prep[i] = prep[i - 1] + (s[i] == 'P');
        prer[i] = prer[i - 1] + (s[i] == 'R');
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        int l = i, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (prer[mid] - prer[i - 1] >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int L = r;
        l = i, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (prep[mid] - prep[i - 1]) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        int R = r;
        if (prep[R] - prep[i - 1]) {
            continue;
        }
        if (prer[L] - prer[i - 1] < k) {
            continue;
        }
        if (L <= R) {
            ans += R - L + 1;
        }
    }
    cout << ans << endl;
    return 0;
}