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

int n, m;
int a[N];

int ok(int z) {
    int cnt = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (sum > z) {
            sum = a[i];
            ++cnt;
        }
        if (sum > z) {
            return 0;
        }
    }
    ++cnt;
    return cnt <= m;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int L = 1, R = 1e9;
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