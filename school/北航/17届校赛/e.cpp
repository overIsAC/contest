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

int n, q, L;

struct Node {
    int l, r, id;
    int type;
    bool operator<(Node &other) const {
        if (l == other.l) {
            return type < other.type;
        }
        return l < other.l;
    }
} a[N];

int ans[N];
int tr[N];

void add(int *tr, int p, int v) {
    for (; p; p -= p & -p) {
        tr[p] = min(tr[p], v);
    }
}

int ask(int *tr, int p) {
    int ans = 1e9;
    for (; p <= L; p += p & -p) {
        ans = min(ans, tr[p]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q >> L;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].l >> a[i].r;
        a[i].type = 1;
        a[i].id = i;
    }
    for (int i = 1; i <= q; ++i) {
        cin >> a[i + n].l >> a[i + n].r;
        a[i + n].type = 2;
        a[i + n].id = i;
    }
    sort(a + 1, a + n + q + 1);
    memset(tr, 0x3f, sizeof(tr));
    for (int i = 1; i <= q + n; ++i) {
        if (a[i].type == 1) {
            add(tr, a[i].r, a[i].id);
        } else {
            ans[a[i].id] = ask(tr, a[i].r);
            if (ans[a[i].id] > 1e8) {
                ans[a[i].id] = 0;
            }
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}