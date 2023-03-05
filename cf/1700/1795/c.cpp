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

int n, a[N], b[N];
LL pre[N];

int tr[N];
LL c[N];

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + b[i];
            tr[i] = 0;
            c[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            int l = i, r = n;
            if (b[i] >= a[i]) {
                c[i] += a[i];
                continue;
            }
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (pre[mid] - pre[i - 1] <= a[i]) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            };
            add(tr, i, 1);
            add(tr, r + 1, -1);
            a[i] -= pre[r] - pre[i - 1];
            c[r + 1] += min(a[i], b[r + 1]);
        }
        for (int i = 1; i <= n; ++i) {
            cout << (LL)ask(tr, i) * b[i] + c[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}