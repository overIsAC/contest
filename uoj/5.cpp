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
const int N = 3 + 1e6;

char s[N];
int n;
int ne[N], num[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> s + 1;
        n = strlen(s + 1);

        num[1] = 1;

        for (int i = 2, j = 0; i <= n; ++i) {
            while (j && s[j + 1] != s[i]) {
                j = ne[j];
            }
            if (s[j + 1] == s[i]) {
                ++j;
            }
            ne[i] = j;
            num[i] = num[j] + 1;
        }
        int ans = 1;
        for (int i = 1, j = 0; i <= n; ++i) {
            while (j && s[j + 1] != s[i]) {
                j = ne[j];
            }
            if (s[j + 1] == s[i]) {
                ++j;
            }
            while (i / 2 < j) {
                j = ne[j];
            }
            ans = (LL)ans * (num[j] + 1) % mod;
        }
        cout << ans << '\n';
    }

    return 0;
}