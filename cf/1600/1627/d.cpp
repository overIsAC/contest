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
const int N = 3 + 1e6;

int n, a[N];
int f[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[a[i]] = 1;
    }
    int ans = 0;
    for (int i = 1e6; i >= 1; --i) {
        if (f[i]) {
            continue;
        }
        int last = 0;
        for (int j = i + i; j <= 1e6; j += i) {
            if (f[j]) {
                if (gcd(last, j) == i) {
                    ++ans;
                    f[i] = 1;
                    break;
                }
                last = j;
            }
        }
    }
    cout << ans << endl;

    return 0;
}