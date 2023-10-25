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

int n, L, R;

int calc(int v) {
    if (L <= v && v <= R) {
        return v % n;
    } else {
        return 0;
    }
}

int main() {
    cin >> n >> L >> R;
    int ans = max(calc(L), calc(R));
    for (int i = 0; i <= 2e5; ++i) {
        ans = max(ans, calc(L + i));
        ans = max(ans, calc(R - i));
        ans = max(ans, calc(R / n * n + i));
        ans = max(ans, calc(R / n * n - i));
        ans = max(ans, calc((L + 1) / n * n + i));
        ans = max(ans, calc((L + 1) / n * n - i));
    }
    cout << ans << endl;
    return 0;
}