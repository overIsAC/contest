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
const int N = 3 + 1e3;

int n, m;
char s[N][N], t[N][N];

int main() {
    LL n;
    cin >> n;
    LL c = n / 3 * 2 + n % 3;
    cout << n * (n - 1) / 2 - c * (c - 1) / 2 << endl;

    return 0;
}