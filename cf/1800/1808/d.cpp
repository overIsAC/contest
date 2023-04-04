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
const int N = 3 + 2e5;

int n, k;
int a[N];
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int c = 0;
    LL ans = 0;
    for (int i = 1, j = 1; i <= n; i += 2) {
        if (i - j + 1 >= k) {
            ans += c - cnt[a[i]];
            --cnt[a[j]];
            --c;
            j += 2;
            if (n - i + 1 < k) {
                --cnt[a[j]];
                --c;
                j += 2;
            }
        }
        ++cnt[a[i]];
        ++c;
    }
    memset(cnt, 0, sizeof(cnt));
    c = 0;
    for (int i = 2, j = 2; i <= n; i += 2) {
        if (i - j + 1 >= k) {
            ans += c - cnt[a[i]];
            --cnt[a[j]];
            --c;
            j += 2;
            if (n - i + 1 < k) {
                --cnt[a[j]];
                --c;
                j += 2;
            }
        }
        ++cnt[a[i]];
        ++c;
    }
    cout << ans << endl;
    return 0;
}
