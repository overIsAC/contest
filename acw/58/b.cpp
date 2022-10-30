#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N];
int dp[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        int j = i;
        while (j + 1 <= n && a[j + 1] <= a[j] * 2) ++j;
        ans = max(ans, j - i + 1);
        i = j;
    }

    printf("%d\n", ans);
    return 0;
}