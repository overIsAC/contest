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

int n, k;
int a[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        ++mp[a[i]];
    }
    int ans = 0;
    while (k--) {
        for (auto &[x, y] : mp) {
            if (y) {
                --y;
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}