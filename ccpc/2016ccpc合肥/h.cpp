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
const int N = 3 + 1e5;

int n, a[N], q;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
        }
        scanf("%d", &q);
        while (q--) {
            int x;
            scanf("%d", &x);
            int ans = 0, temp = 1e9;
            for (int i = 1; i <= n; ++i) {
                int pre = 0;
                for (int j = i; j <= n; ++j) {
                    pre ^= a[j];
                    if (abs(pre - x) < temp) {
                        temp = abs(pre - x);
                        ans = j - i + 1;
                    } else if (abs(pre - x) == temp) {
                        ans = max(ans, j - i + 1);
                    }
                }
            }
            printf("%d\n", ans);
        }
        puts("");
    }

    return 0;
}