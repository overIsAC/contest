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
    int n;
    cin >> n;
    int ans1 = 1, ans2 = 0;
    while (n > 0) {
        if (n % 3 == 1) {
            if (ans2 == 0) {
                ans2 = ans1;
            }
        }
        n = n - (n + 2) / 3;
        if (n == 0) {
            break;
        }
        ++ans1;
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}