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
        int a, b, c;
        cin >> a >> b >> c;
        if (a + c <= b) {
            cout << 0 << endl;
            continue;
        }
        int l = 0, r = c;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (b + mid < a + (c - mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << r + 1 << endl;
    }
    return 0;
}