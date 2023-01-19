#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    LL n, k;
    cin >> n >> k;
    cout << ((n - 1) * 6 + 5) * k << endl;
    for (int i = 0, j = 1; j <= n; i += 6, j += 1) {
        cout << (i + 1) * k << ' ' << (i + 2) * k << ' ' << (i + 3) * k << ' ' << (i + 5) * k << endl;
    }
    return 0;
}