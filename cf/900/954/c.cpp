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
    int q;
    cin >> q;
    vector<int> a(q);
    for (auto &i : a) {
        cin >> i;
    }
    int n = 1e9, m = 1e9;
    for (int i = 1; i < q; ++i) {
        int t = abs(a[i] - a[i - 1]);
        if (t == 0) {
            cout << "NO" << endl;
            return 0;
        }
        if (t != 1) {
            m = t;
        }
    }
    for (int i = 1; i < q; ++i) {
        int t = abs(a[i] - a[i - 1]);
        if (t != 1) {
            if (m != t) {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            int y1 = (a[i] - 1) / m + 1;
            int y2 = (a[i - 1] - 1) / m + 1;
            if (y1 != y2) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    cout << n << ' ' << m << endl;

    return 0;
}