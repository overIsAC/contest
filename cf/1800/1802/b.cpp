#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
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
        int u = 0, v = 0, w = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 1) {
                ++w;
            } else {
                if (w) {
                    if (!v) {
                        ++v;
                        --w;
                    }
                    u += w;
                    w = 0;
                }
            }
            ans = max((u + 1) / 2 + v + w, ans);
        }
        cout << ans << endl;
    }
    return 0;
}