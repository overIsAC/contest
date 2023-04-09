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

int n, q, a[N];
LL pre[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        int l = 1, r = n;
        auto query = [&](int l, int r) {
            cout << "? " << r - l + 1 << ' ';
            for (int i = l; i <= r; ++i) {
                cout << i << ' ';
            }
            cout << endl;
            LL v;
            cin >> v;
            return v;
        };
        while (l < r) {
            int mid = l + r >> 1;
            if (query(l, mid) == pre[mid] - pre[l - 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        cout << "! " << r << endl;
    }
    return 0;
}