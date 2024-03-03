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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = i;
        }
        a.back() = 0;
        for (int i = 0; i < 31; ++i) {
            int z = 0;
            for (int j = 0; j + 1 < n; ++j) {
                z ^= a[j] >> i & 1;
            }
            a.back() |= z << i;
        }
        int p = -1;
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] == a.back()) {
                p = i;
            }
        }
        if (p != -1) {
            if (p == 0) {
                a[p + 1] ^= 1 << 23;
            } else {
                a[p - 1] ^= 1 << 23;
            }
            a.back() ^= 1 << 23;
        }
        for (auto& i : a) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}