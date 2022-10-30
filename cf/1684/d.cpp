#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N], k;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        set<LL> s;
        LL sum = 0;
        for (int kk = k, i = n; i; --i) {
            if (kk > 0) {
                --kk;
                s.insert(a[i]);
            } else {
                sum += a[i];
            }
        }
        cout << sum << endl;
        for (int i = n - k; i; --i) {
            LL v = *s.begin() - a[i] + n - i - k + 1;
            if (v < 0) {
                sum += v;
                s.erase(s.begin());
                s.insert(a[i]);
            }
            cout << sum << endl;
        }
        cout << sum << endl;
    }
    return 0;
}