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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N], b[N];
int ans1[N], ans2[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        int p = n, pp = n;
        for (int i = n; i; --i) {
            while (p > 1 && b[p - 1] >= a[i]) {
                --p;
            }
            ans1[i] = b[p] - a[i];
            ans2[i] = b[pp] - a[i];
            if (i == p) {
                pp = i - 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans1[i] << ' ';
        }
        cout << endl;
        for (int i = 1; i <= n; ++i) {
            cout << ans2[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}