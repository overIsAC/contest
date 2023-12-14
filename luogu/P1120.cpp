#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 100;

int n, a[N];
int sum;

int len, tot;
int b[N];

int dfs(int p) {
    if (p == n + 1) {
        return 1;
    }
    for (int i = 1; i <= tot; ++i) {
        if (b[i] + a[p] <= len) {
            b[i] += a[p];
            if (dfs(p + 1)) {
                return 1;
            }
            b[i] -= a[p];
        }
    }
    return 0;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = a[1]; i <= sum; ++i) {
        if (sum % i == 0) {
            len = i;
            tot = sum / i;
            if (dfs(1)) {
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}