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
        for (auto &i : a) {
            cin >> i;
        }
        LL u = 0, v = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                u += a[i];
            } else {
                v += a[i];
            }
        }
        if (u > v) {
            for (int i = 0; i < n; ++i) {
                if (i & 1) {
                } else {
                    a[i] = 1;
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                if (i & 1) {
                    a[i] = 1;
                } else {
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}