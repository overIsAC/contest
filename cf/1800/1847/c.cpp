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

int n, k, a[N];
int pre[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre[i] = pre[i - 1] ^ a[i];
        }
        vector<int> cnt(1 << 8);
        cnt[0] = 1;
        int ans = a[n];
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 1 << 8; ++j) {
                if (cnt[j]) {
                    ans = max(pre[i] ^ j, ans);
                }
            }
            cnt[pre[i]] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}