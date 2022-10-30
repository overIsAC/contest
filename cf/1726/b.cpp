#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (m < n) {
            cout << "No" << endl;
            continue;
        }
        vector<int> a(n, m / n);
        if (n & 1) {
            vector<int> b(n, 1);
            swap(a, b);
            a[0] += m - n;
        } else if (m % n) {
            if (n - m % n & 1) {
                cout << "No" << endl;
                continue;
            }
            for (int i = 0; i < m % n; ++i) {
                ++a[i];
            }
        }
        cout << "Yes" << endl;
        for (auto &i : a) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}