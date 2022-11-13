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
const int N = 3 + 1e6;

int n, a[N];
int b[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        ++b[a[i]];
    }
    LL ans = 0;
    for (int i = 0; i <= 1000; ++i) {
        for (int j = i + 1; j <= 1000; ++j) {
            ans += abs(i + j - 1000LL) * b[i] * b[j];
        }
        ans += abs(i + i - 1000LL) * b[i] * (b[i] - 1) / 2;
        ans += abs(i + i - 1000LL) * b[i];
    }
    cout << ans << endl;
    return 0;
}