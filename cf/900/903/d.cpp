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
const int N = 3 + 1e6;

int n, a[N], b[N], t;
LL cnt[N];
int num[N];

void write(__int128_t x) {
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    if (x >= 10) {
        write(x / 10);
    }
    cout << (int)(x % 10);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = -1; j <= 1; ++j) {
            b[++t] = a[i] + j;
        }
    }
    sort(b + 1, b + t + 1);
    t = unique(b + 1, b + t + 1) - b - 1;
    __int128_t ans = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (LL)(i - 1) * a[i] - sum;
        int p = lower_bound(b + 1, b + t + 1, a[i]) - b;
        for (int j = -1; j <= 1; ++j) {
            if (abs(b[p + j] - a[i]) <= 1) {
                ans -= (LL)num[p + j] * a[i] - cnt[p + j];
            }
        }
        sum += a[i];
        cnt[p] += a[i];
        ++num[p];
    }
    write(ans);
    return 0;
}