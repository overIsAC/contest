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
const int N = 3 + 1e5;

int n, m, k;
int b[N], t;
int a[N], R[N], L[N];
int block[N], blo;
int tr[N];
int l, r;
LL ans[N], temp;

struct Query {
    int l, r;
    int id;
    bool operator<(const Query &other) const {
        if (block[l] != block[other.l]) {
            return block[l] < block[other.l];
        }
        if (block[l] & 1) {
            return r < other.r;
        }
        return r > other.r;
    }
} query[N];

void add(int *tr, int p, int v) {
    for (; p <= t; p += p & -p) {
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
    while (~scanf("%d%d%d", &n, &m, &k)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
        }
        t = 0;
        for (int i = 1; i <= n; ++i) {
            b[++t] = a[i];
            b[++t] = a[i] + k;
            b[++t] = a[i] - k;
        }
        sort(b + 1, b + t + 1);
        t = unique(b + 1, b + t + 1) - b - 1;
        for (int i = 1; i <= t; ++i) {
            tr[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            L[i] = lower_bound(b + 1, b + t + 1, a[i] - k) - b;
            R[i] = lower_bound(b + 1, b + t + 1, a[i] + k) - b;
            a[i] = lower_bound(b + 1, b + t + 1, a[i]) - b;
        }
        blo = n / sqrt(m);
        for (int i = 1; i <= n; ++i) {
            block[i] = (i - 1) / blo + 1;
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d", &query[i].l, &query[i].r);
            query[i].id = i;
            ans[i] = 0;
        }
        sort(query + 1, query + m + 1);
        l = 1;
        r = 0;
        for (int i = 1; i <= m; ++i) {
            while (l < query[i].l) {
                add(tr, a[l], -1);
                temp -= ask(tr, R[l]) - ask(tr, L[l] - 1);
                ++l;
            }
            while (l > query[i].l) {
                --l;
                temp += ask(tr, R[l]) - ask(tr, L[l] - 1);
                add(tr, a[l], 1);
            }
            while (r < query[i].r) {
                ++r;
                temp += ask(tr, R[r]) - ask(tr, L[r] - 1);
                add(tr, a[r], 1);
            }
            while (r > query[i].r) {
                add(tr, a[r], -1);
                temp -= ask(tr, R[r]) - ask(tr, L[r] - 1);
                --r;
            }
            ans[query[i].id] = temp;
        }
        for (int i = 1; i <= m; ++i) {
            printf("%lld\n", ans[i]);
        }
    }
    return 0;
}

//https://blog.csdn.net/qq_41117236/article/details/90413336