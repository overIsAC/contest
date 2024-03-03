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

LL c[1234][1234];

int main() {
    c[0][0] = 1;
    for (int i = 1; i < 1234; ++i) {
        c[i][0] = 1;
        for (int j = 1; j < 1234; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        LL ans = 1;
        vector<int> a(m);
        for (auto& i : a) {
            cin >> i;
        }
        n = accumulate(a.begin(), a.end(), 0);
        for (auto& i : a) {
            ans = ans * c[n][i] % mod;
            n -= i;
        }
        cout << ans << endl;
    }

    return 0;
}