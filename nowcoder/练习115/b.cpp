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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];

int f(int L, int R, int cnt) {
    --cnt;
    int mid = L + R >> 1;
    if (!cnt) {
        return mid;
    }
    if (L == R) {
        return -1;
    }
    if (mid - L > R - mid) {
        return f(L, mid - 1, cnt);
    } else {
        return f(mid + 1, R, cnt);
    }
}

void solve() {
    int L, R, cnt;
    cin >> L >> R >> cnt;
    cout << f(L, R, cnt) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}