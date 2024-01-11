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
const int N = 3 + 1e6;

int n, h[N], v[N];
int stk[N], top;
LL ans[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i] >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        while (top && h[stk[top]] < h[i]) {
            ans[i] += v[stk[top]];
            --top;
        }
        stk[++top] = i;
    }
    top = 0;
    for (int i = n; i >= 1; --i) {
        while (top && h[stk[top]] < h[i]) {
            ans[i] += v[stk[top]];
            --top;
        }
        stk[++top] = i;
    }
    cout << *max_element(ans + 1, ans + n + 1) << endl;
    return 0;
}