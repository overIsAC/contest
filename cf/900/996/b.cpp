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

int n, a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mn = INT_MAX, ans = 0;
    for (int i = 0; i < n; ++i) {
        int t = a[i] / n;
        t = t * n;
        if (a[i] % n <= i) {
            t += i;
        } else {
            t += n + i;
        }
        mn = min(mn, t);
        if (mn == t) {
            ans = i;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}