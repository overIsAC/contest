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
const int N = 3 + 2e5;

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int flag = 0, last = a[1];
        cout << 1;
        for (int i = 2; i <= n; ++i) {
            if (!flag) {
                if (last <= a[i]) {
                    cout << 1;
                    last = a[i];
                    continue;
                }
                if (!(-1e9 <= a[i] && a[i] <= a[1])) {
                    cout << 0;
                    continue;
                }
                flag = 1;
                last = -1e9;
            }
            if (flag) {
                if (last <= a[i] && a[i] <= a[1]) {
                    cout << 1;
                    last = a[i];
                } else {
                    cout << 0;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
