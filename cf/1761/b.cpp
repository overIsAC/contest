#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 1;
        if (n <= 2) {
            ans = n;
        } else {
            for (int i = 0; i < n; ++i) {
                int res = 0;
                for (int j = (i+ 1) % n; j != i; j = (j + 1) % n) {
                    ++res;
                    int k = (j + 1) % n;
                    if (k != i && a[i] == a[k]) {
                        j = k;
                    }
                }
                ans = max(ans, res + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
5
3 1 2 1 2
2
1 2
6
1 2 1 2 1 2
*/
