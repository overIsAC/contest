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
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1) {
        for (int i = 1; i <= m; ++i) {
            cout << i + 1 << ' ';
        }
        return 0;
    }
    if (m == 1) {
        for (int i = 1; i <= n; ++i) {
            cout << i + 1 << ' ';
        }
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << (i + m) * j << ' ';
        }
        cout << endl;
    }
    return 0;
}