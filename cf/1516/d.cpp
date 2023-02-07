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
int ans[N];
vector<int> last[N];
vector<int> ve[N];
int vis[N];

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

    for (int i = 1; i <= n; ++i) {
        ve[a[i]].push_back(i);
    }
    for (int i = 2; i <= 1e5; ++i) {
        for (int j = i + i; j <= 1e5; j += i) {
            ve[i].insert(ve[i].begin(), ve[j].begin(), ve[j].end());
        }
        sort(ve[i].begin(), ve[i].end());
    }

    for (int i = 2; i <= 1e5; ++i) {
        for (int j = 1; j < ve[i].size(); ++j) {
            last[ve[i][j]].push_back(ve[i][j - 1]);
        }
    }

    int p = 1;

    for (int i = 1; i <= q; ++i) {
        while (p <= query[i].r) {
            for (auto &j : last[p]) {
                if (!vis[j]) {
                    add(tr, j, -1);
                    vis[j] = 1;
                }
            }
            add(tr, p, 1);
            ++p;
        }
        ans[query[i].id] = max(query[i].r - query[i].l + 1 - (ask(tr, query[i].r) - ask(tr, query[i].l - 1)), 1);
    }
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}