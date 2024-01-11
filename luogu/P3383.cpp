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

int p[N], v[N];
int t;
int q[N];
LL L, R;

int main() {
    for (int i = 2; i < N; ++i) {
        if (!v[i]) {
            p[++t] = i;
            // cout << i << endl;
        }
        for (int j = 1; j <= t && p[j] * i < N; ++j) {
            v[p[j] * i] = 1;
            if (i % p[j] == 0) {
                break;
            }
        }
    }
    cin >> L >> R;
    for (int i = 1; i <= t; ++i) {
        LL j = L / p[i] * p[i];
        while (j < L || j == p[i]) {
            j += p[i];
        }
        for (; j <= R; j += p[i]) {
            q[j - L] = 1;
            // cout << j << ' ';
        }
        // cout << endl;
    }
    if (L <= 1 && 1 <= R) {
        q[1 - L] = 1;
    }
    int ans = 0;
    for (LL i = L; i <= R; ++i) {
        if (q[i - L] == 0) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}