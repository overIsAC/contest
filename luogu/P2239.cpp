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
    int n, i, j;
    cin >> n >> i >> j;
    int ans = 0;
    for (int w = 1; w <= n; ++w) {
        if (i == w || j == w || n - w + 1 == i || n - w + 1 == j) {
            if (i == w) {
                cout <<ans + 
            }
        }
    }
    return 0;
}