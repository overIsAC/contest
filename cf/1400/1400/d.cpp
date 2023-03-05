#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3e3;

int n, a[N];
int c[N][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                ans += c[a[i]][a[j]];
            }
            for (int j = 1; j < i; ++j) {
                ++c[a[j]][a[i]];
            }
        }
        cout << ans << endl;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                c[a[j]][a[i]] = 0;
            }
        }
    }
    return 0;
}