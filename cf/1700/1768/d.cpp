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
int tr[N];
int p[N];
int L[N], R[N];

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
            tr[i] = 0;
            p[a[i]] = i;
        }
        LL temp = 0;
        for (int i = n; i; --i) {
            R[i] = ask(tr, a[i] - 1);
            temp += R[i];
            add(tr, a[i], 1);
        }
        for (int i = 1; i <= n; ++i) {
            tr[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            L[i] = ask(tr, n) - ask(tr, a[i]);
            add(tr, a[i], 1);
        }
        for (int i = 1; i <= n; ++i) {
            cout << i << ' ' << L[i] << ' ' << R[i] << endl;
        }
        LL ans = 1e18;
        cout << temp << endl;
        for (int i = 1; i < n; ++i) {
            LL t = temp - L[p[i]] - R[p[i]] - L[p[i + 1]] - R[p[i + 1]];
            if (p[i] > p[i + 1]) {
                ++t;
            }
          
        }
        cout << ans << endl;
    }
    return 0;
}