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
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<LL> pre1(n + 1);
        vector<int> pre2(n + 1);
        for (auto& i : a) {
            cin >> i;
        }
        for (int i = 1; i <= n; ++i) {
            pre1[i] = pre1[i - 1] + a[i - 1] - 1;
            pre2[i] = pre2[i - 1];
            if (a[i - 1] == 1) {
                ++pre2[i];
            }
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (l != r && pre1[r] - pre1[l - 1] >= pre2[r] - pre2[l - 1]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}