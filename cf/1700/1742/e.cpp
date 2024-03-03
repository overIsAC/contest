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

int n, q;
int a[N], k[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<int> b;
        vector<LL> c;
        b.push_back(a[1]);
        c.push_back(a[1]);
        for (int i = 2; i <= n; ++i) {
            if (b.back() < a[i]) {
                b.push_back(a[i]);
                c.push_back(c.back());
            }
            c.back() += a[i];
        }
        // for (int i = 0; i < c.size(); ++i) {
        //     cout << i << ' ' << b[i] << ' ' << c[i] << endl;
        // }
        while (q--) {
            int k;
            cin >> k;
            auto p = upper_bound(b.begin(), b.end(), k);
            if (p == b.begin()) {
                cout << 0 << ' ';
                continue;
            }
            --p;
            cout << c[p - b.begin()] << ' ';
        }
        cout << endl;
    }
    return 0;
}