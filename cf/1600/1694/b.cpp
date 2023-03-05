#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

char s[N];
int n;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> s + 1;
        LL ans = 1;
        for (int i = 2; i <= n; ++i) {
            if (s[i] != s[i - 1]) ans += i - 1;
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}