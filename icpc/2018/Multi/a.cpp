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
const int N = 3 + 5e6;

unsigned int stk[N];
int top;

void solve(int T) {
    int n, p, q, m;
    unsigned int SA, SB, SC;
    auto rnd61 = [&]() {
        SA ^= SA << 16;
        SA ^= SA >> 5;
        SA ^= SA << 1;
        unsigned int t = SA;
        SA = SB;
        SB = SC;
        SC ^= t ^ SA;
        return SC;
    };

    top = 0;

    auto PUSH = [&](unsigned int x) {
        top += 1;
        stk[top] = max(stk[top - 1], x);
    };

    auto POP = [&]() {
        --top;
    };

    LL ans = 0;

    cin >> n >> p >> q >> m >> SA >> SB >> SC;
    for (int i = 1; i <= n; ++i) {
        if (rnd61() % (p + q) < p) {
            PUSH(rnd61() % m + 1);
        } else {
            if (top) {
                POP();
            }
        }
        ans ^= (LL)i * stk[top];
    }

    cout << "Case #" << T << ": " << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
    return 0;
}
