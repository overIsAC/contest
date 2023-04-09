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
    int n, p, q;
    string s;
    cin >> n >> p >> q >> s;
    for (int i = 0; i * p <= n; ++i) {
        int j = n - i * p;
        if (j % q) {
            continue;
        }
        j /= q;
        cout << i + j << endl;
        for (int k = 0; k < i * p; ++k) {
            cout << s[k];
            if ((k + 1) % p == 0) {
                cout << endl;
            }
        }
        for (int k = 1; k <= j * q; ++k) {
            cout << s[i * p + k - 1];
            if (k % q == 0) {
                cout << endl;
            }
        }
        return 0;
    }
    cout << -1 << endl;
    return 0;
}