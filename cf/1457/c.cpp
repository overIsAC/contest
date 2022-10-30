#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, p, k, x, y;
char s[N];
int suf[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> p >> k;
        cin >> s + 1;
        cin >> x >> y;
        for (int i = n; i; --i) {
            suf[i] = 0;
            if (s[i] == '0') ++suf[i];
            if (i + k <= n) suf[i] += suf[i + k];
        }
        int ans = INT_MAX;
        for (int i = p, j = 0; i <= n; ++i, ++j) {
            ans = min(ans, suf[i] * x + y * j);
        }
        cout << ans << endl;
    }
    return 0;
}