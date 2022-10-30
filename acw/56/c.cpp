#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

LL p, q, b;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &p, &q, &b);
        q /= __gcd(p, q);
        LL t = __gcd(q, b);
        while (t > 1) {
            q /= t;
            t = __gcd(q, b);
        }
        if (q > 1)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}