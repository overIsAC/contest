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
    int n;
    cin >> n;
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        int z = mid, cnt = mid;
        while (z >= 3) {
            cnt += z / 3;
            z = z % 3 + z / 3;
        }
        if (cnt >= n) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << endl;
    return 0;
}