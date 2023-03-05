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
const int N = 3 + 3e5;

int n, a[N];
int stk[N], top;
LL sum[N];
LL pre[N];
LL temp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        top = 0;
        for (int i = 1; i <= n; ++i) {
            while (top && a[stk[top]] > a[i] - (i - stk[top])) {
                --top;
            }
            int t = min(a[i], i - stk[top]);
            stk[++top] = i;
            sum[top] = sum[top - 1] + (LL)(a[i] + (a[i] - t + 1)) * t / 2;
            temp[i] = sum[top];
        }
        top = 0;
        reverse(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            while (top && a[stk[top]] > a[i] - (i - stk[top])) {
                --top;
            }
            int t = min(a[i], i - stk[top]);
            stk[++top] = i;
            sum[top] = sum[top - 1] + (LL)(a[i] + (a[i] - t + 1)) * t / 2;
            temp[n - i + 1] += sum[top] - a[i];
        }
        reverse(a + 1, a + n + 1);
        LL ans = 1e18;
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, pre[n] - temp[i] + a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}