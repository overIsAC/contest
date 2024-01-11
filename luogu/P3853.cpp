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

int l, n, k;
int a[N];

int ok(int v) {
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == a[i - 1]) {
            continue;
        }
        cnt += (a[i] - a[i - 1]) / v;
        if ((a[i] - a[i - 1]) % v == 0) {
            --cnt;
        }
        if (cnt > k) {
            return 0;
        }
    }
    return 1;
}

int main() {
    cin >> l >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[++n] = 0;
    a[++n] = l;
    sort(a + 1, a + n + 1);

    int L = 1, R = l;
    while (L < R) {
        int mid = L + R >> 1;
        if (ok(mid)) {
            R = mid;
        } else {
            L = mid + 1;
        }
    }
    cout << R << endl;
    return 0;
}