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
const int N = 3 + 2e5;

int n, a[N];
int p[N];

int tr[N];

void add(int *tr, int p, int v) {
    for (; p <= n; p += p & -p) {
        tr[p] += v;
    }
}

int ask(int *tr, int p) {
    int ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            p[a[i]] = i;

            tr[i] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            add(tr, i, 1);
        }

        int ans = 0;
        for (int i = 1, j = n; i < j; ++i, --j) {
            if (ask(tr, p[i] - 1) || ask(tr, n) - ask(tr, p[j])) {
                ans = i;
            }
            add(tr, p[i], -1);
            add(tr, p[j], -1);
        }
        cout << ans << endl;
    }
    return 0;
}