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

int n;
char s[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s + 1;
        int x = 0, y = 0;
        double ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'L') {
                --x;
            } else if (s[i] == 'R') {
                ++x;
            } else if (s[i] == 'U') {
                ++y;
            } else {
                --y;
            }
            ans = max(ans, sqrt(x * x + y * y));
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}