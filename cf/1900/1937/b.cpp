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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string u, v;
        cin >> u >> v;
        string ans;
        int flag = 0;
        int p = -1;
        for (int i = 0; i < n; ++i) {
            if (flag) {
                ans += v[i];
            } else {
                ans += u[i];
                if (i + 1 < n && u[i + 1] <= v[i]) {
                } else {
                    ans += v[i];
                    flag = 1;
                    p = i;
                }
            }
        }
        if (!flag) {
            p = n - 1;
            ans += v.back();
        }
        cout << ans << endl;
        int cnt = 0;
        for (int i = p; i >= 1; --i) {
            if (u[i] == v[i - 1]) {
                ++cnt;
            } else {
                break;
            }
        }
        cout << cnt + 1 << endl;
    }
    return 0;
}