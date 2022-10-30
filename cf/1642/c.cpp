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
const int N = 3 + 2e5;

int n, a[N], x;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        map<LL, int> m;
        int ans = 0;

        for (int i = 1; i <= n; ++i) {
            ++m[a[i]];
        }
        for (auto &i : m) {
            if (!i.second) continue;
            if (i.second <= m[(LL)i.first * x]) {
                m[(LL)i.first * x] -= i.second;
            } else {
                ans += i.second - m[(LL)i.first * x];
                m[(LL)i.first * x] = 0;
            }
        }

        cout << ans << endl;
    }
    return 0;
}