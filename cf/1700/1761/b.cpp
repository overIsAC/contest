
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

int n;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, int> mp;
        for (auto &i : a) {
            ++mp[i];
        }
        int one = 0;
        for (auto [x, y] : mp) {
            if (y == 1) {
                one = 1;
            }
        }
        if (one) {
            cout << n << endl;
            continue;
        }
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != a[(i + 2) % n]) {
                flag = 1;
            }
        }
        if (flag) {
            cout << n << endl;
        } else {
            cout << n / 2 + 1 << endl;
        }
    }
    return 0;
}