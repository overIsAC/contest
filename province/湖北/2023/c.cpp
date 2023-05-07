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
    int n, m;
    cin >> n >> m;

    if (n == 1 || m == 1) {
        cout << max(n, m) / 2 + 1 << endl;
    } else {
        cout << min(n, m) + (abs(n - m) + 1) / 2 << endl;
    }
    return 0;
}