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

int n, a[N], q;
int tr[N];
int cnt[N];
int ans[N];

struct Query {
    int l, r, id;
    bool operator<(const Query &other) const {
        return r < other.r;
    }
} query[N];

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
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> query[i].l >> query[i].r;
        query[i].id = i;
    }
    sort(query + 1, query + q + 1);

    auto insert = [&](int v) {
        for (int i = 1; i * i <= v; ++i) {
            if (v % i == 0) {
                if (cnt[i]) {
                    add(tr, cnt[i], -1);
                    cnt[i] = 0;
                }
                if (i * i != v) {
                    if (cnt[v / i]) {
                        add(tr, cnt[v / i], -1);
                        cnt[v / i] = 0;
                    }
                }
            }
        }
    };

    int p = 1;

   
    return 0;
}