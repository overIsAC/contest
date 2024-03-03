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

int n, q;
int a[N];
string s[N];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        s[i] = to_string(a[i]);
    }

    while (q--) {
        int m;
        string t;
        cin >> m >> t;

        string ans = "-1";
        for (int i = 1; i <= n; ++i) {
            if (s[i].size() >= m && s[i].substr(s[i].size() - m) == t) {
                ans = s[i];
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}