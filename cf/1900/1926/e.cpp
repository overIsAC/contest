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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        if (k <= (n + 1) / 2) {
            cout << k * 2 - 1 << endl;
            continue;
        }

        k -= (n + 1) / 2;

        for (int i = 2, j = 4;; i *= 2, j *= 2) {
            int cnt = n / i - n / j;
            if (k <= cnt) {
                cout << (k - 1) * j + i << endl;
                break;
            }
            k -= cnt; 
        }
    }
    return 0;
}

// 1 2 3 4 5 6 7 8 10 12 13 14 15 16
// 0 2 0 4 0 2 0 8 2  4  0  2  0  16