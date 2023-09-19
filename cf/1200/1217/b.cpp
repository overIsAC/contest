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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        int _max = *max_element(a.begin(), a.end());
        if (_max >= x) {
            cout << 1 << endl;
            continue;
        }
        int dif = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i]) {
                dif = max(dif, a[i] - b[i]);
            }
        }
        if (!dif) {
            cout << -1 << endl;
            continue;
        }
        x -= _max;
        int ans = 1;
        ans += (x + dif - 1) / dif;
        cout << ans << endl;
    }
    return 0;
}