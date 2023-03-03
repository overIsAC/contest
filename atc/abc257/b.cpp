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

int n, k, q;
int a[N], b[N];

int main() {
    cin >> n >> k >> q;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
        b[a[i]] = 1;
    }
    while (q--) {
        int p;
        cin >> p;
        b[a[p]] = 0;
        if (a[p] + 1 <= n && !b[a[p] + 1]) {
            ++a[p];
        }
        b[a[p]] = 1;
    }
    for (int i = 1; i <= k; ++i) {
        cout << a[i] << ' ';
    }
    return 0;
}