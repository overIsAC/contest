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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto& i : a) {
            cin >> i;
        }
        auto check = [&](LL z, int water) {
            for (auto& i : a) {
                if (i >= z) {
                    continue;
                }
                water -= z - i;
                if (water < 0) {
                    return 0;
                }
            }
            return 1;
        };
        LL l = 1, r = 2e9;
        while (l < r) {
            LL mid = l + r + 1 >> 1;
            if (check(mid, x)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << r << endl;
    }

    return 0;
}