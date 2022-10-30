#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) continue;
            while (i + 1 <= n && a[i + 1]) ++i;
            ++ans;
        }
        if (ans > 1) ans = 2;
        cout << ans << endl;
    }
    return 0;
}