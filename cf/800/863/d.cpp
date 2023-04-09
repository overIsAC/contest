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
const int N = 3 + 2e5;

int n, q, m;
int a[N];
int t[N], l[N], r[N];

int main() {
    cin >> n >> q >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> t[i] >> l[i] >> r[i];
    }
    while (m--) {
        int b;
        cin >> b;
        for (int i = q; i >= 1; --i) {
            if (l[i] <= b && b <= r[i]) {
                if (t[i] == 1) {
                    if (b == l[i]) {
                        b = r[i];
                    } else {
                        b = b - 1;
                    }
                } else {
                    int len = r[i] - l[i] + 1;
                    b -= l[i] - 1;
                    b = len - b + 1;
                    b += l[i] - 1;
                }
            }
        }
        cout << a[b] << ' ';
    }
    return 0;
}