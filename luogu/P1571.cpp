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

int n, m, b[N], a[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = m;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (a[i] >= b[mid]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (a[i] == b[r]) {
            cout << a[i] << ' ';
        }
    }
    return 0;
}