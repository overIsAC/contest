#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 222;

int n, a[N];
char s[N];
bool vis[N];

int main() {
    int T;
    cin >> T;

    auto calc = [&](string &s) -> int {
        int ans = s.size();
        for (int i = 1; i < s.size(); ++i) {
            if (s.size() % i) continue;
            if (s.substr(i) + s.substr(0, i) == s) {
                ans = i;
                break;
            }
        }
        return ans;
    };

    while (T--) {
        cin >> n >> s + 1;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        memset(vis, false, sizeof(vis));
        LL ans = 1;

        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            string ss;
            for (int j = i; !vis[j]; j = a[j]) {
                ss += s[j];
                vis[j] = true;
            }
            LL t = calc(ss);
            LL g = __gcd(t, ans);
            ans = ans / g * t;
        }
        cout << ans << endl;
    }
    return 0;
}