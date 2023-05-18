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

int n, k, a[N];
int top, stk[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (!top || a[stk[top]] < a[i]) {
            stk[++top] = i;
        }
    }
    for (int i = 1; i < top; ++i) {
        if (stk[i + 1] - stk[i] + (stk[i] > 1) > k) {
            cout << stk[i] << endl;
            return 0;
        }
    }
    cout << stk[top] << endl;
    return 0;
}