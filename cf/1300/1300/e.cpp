#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n, a[N];
LL pre[N];
PII stk[N];
int top;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a +i);
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        PII c = {i, i};
        while (top && 1.0 * (pre[stk[top].second] - pre[stk[top].first - 1]) /
                              (stk[top].second - stk[top].first + 1) >=
                          1.0 * (pre[c.second] - pre[c.first - 1]) /
                              (c.second - c.first + 1)) {
            c.first = stk[top].first;
            --top;
        }
        stk[++top] = c;
    }

    for (int i = 1; i <= top; ++i) {
        auto c = stk[i];
        double ans = pre[c.second] - pre[c.first - 1];
        ans /= c.second - c.first + 1;
        for (int j = c.first; j <= c.second; ++j) {
            printf("%.12f\n", ans);
        }
    }

    return 0;
}