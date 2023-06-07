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
    int T;
    cin >> T;
    while (T--) {
        int n, a[111];
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int u = 1, v = n;
        while (u + 1 <= n && a[u + 1]) {
            ++u;
        }
        while (v - 1 <= n && a[v - 1]) {
            --v;
        }
        if (u >= v) {
            cout << 0 << endl;
        } else {
            cout << v - u << endl;
        }
    }
    return 0;
}