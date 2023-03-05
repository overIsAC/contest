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

int n;
int a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n % 2 == 0) {
            cout << "No" << endl;
            continue;
        }
        int mid = (n + 1) / 2;
        for (int i = 1; i <= n; ++i) {
            a[i] = mid;
        }
        for (int i = 1, j = n, v = 1; i < j; ++i, --j, ++v) {
            a[i] += v;
            a[j] -= v;
        }
        cout << "Yes" << endl;
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << ' ' << n + i << endl;
        }
    }
    return 0;
}