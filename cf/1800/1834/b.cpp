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

int main() {
    int T;
    cin >> T;
    while (T--) {
        string L, R;
        cin >> L >> R;
        while (L.size() < R.size()) {
            L = '0' + L;
        }
        int flag = 0;
        int ans = 0;
        for (int i = 0; i < L.size(); ++i) {
            if (flag) {
                ans += 9;
            } else {
                if (L[i] != R[i]) {
                    ans += R[i] - L[i];
                    flag = 1;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}