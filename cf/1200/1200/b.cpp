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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> h(n);
        for (auto &i : h) {
            cin >> i;
        }
        int z = m, ok = 0;
        for (int i = 0; i < n; ++i) {
            if (i + 1 == n) {
                ok = 1;
                break;
            }
            int o = max(0, h[i + 1] - k);
            if (h[i] >= o) {
                z += h[i] - o;
            } else {
                z -= o - h[i];
                if (z < 0) {
                    break;
                }
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}