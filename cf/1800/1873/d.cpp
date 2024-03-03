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
const int N = 3 + 4e5;

int n, k;
char s[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;

        for (int i = 1; i <= n; ++i) {
            cin >> s[i];
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'B') {
                ++ans;
                i += k - 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}