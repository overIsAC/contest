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
    int n, k;
    cin >> n >> k;
    if (k != 0) {
        cout << k + 1 << ' ';
    }
    cout << 1 << ' ';
    for (int i = 2; i <= 2 * n; ++i) {
        if (i == k + 1) {
            continue;
        }
        cout << i << ' ';
    }
    return 0;
}