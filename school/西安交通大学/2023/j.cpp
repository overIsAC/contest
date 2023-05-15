#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using UI = unsigned int;
#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 5e5;

int nxt[N], last[N];
int block[N], blo;
int n, m, a[N];
UI ans[N];
UI now;
int cnt[N];

struct Query {
    int l, r, id;
    bool operator<(const Query& other) const {
        if (block[l] != block[other.l]) {
            return block[l] < block[other.l];
        }
        if (block[l] % 2) {
            return r < other.r;
        }
        return r > other.r;
    }
} query[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        last[i] = cnt[a[i]];
        cnt[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cnt[i] = n + 1;
    }
    for (int i = n; i >= 1; --i) {
        nxt[i] = cnt[a[i]];
        cnt[a[i]] = i;
    }

    blo = sqrt(m);
    for (int i = 1; i <= m; ++i) {
        cin >> query[i].l >> query[i].r;
        query[i].id = i;
        block[i] = (i - 1) / blo + 1;
    }
    sort(query + 1, query + m + 1); 
    int l = 1, r = 0;
    UI L = 0, R = 0;
    int col = 0;
    for (int i = 1; i <= m; ++i) {
        while (r < query[i].r) {
            ++r;
            R += min(r - l + 1, r - last[r]);
            if (last[r] < l) {
                ++col;
            }
            L += col;
            now += R;
        }
        while (r > query[i].r) {
            now -= R;
            L -= col;
            if (last[r] < l) {
                --col;
            }
            R -= min(r - l + 1, r - last[r]);
            --r;
        }
        while (l > query[i].l) {
            --l;
            L += min(r - l + 1, nxt[l] - l);
            if (r < nxt[l]) {
                ++col;
            }
            R += col;
            now += L;
        }
        while (l < query[i].l) {
            now -= L;
            R -= col;
            if (r < nxt[l]) {
                --col;
            }
            L -= min(r - l + 1, nxt[l] - l);
            ++l;
        }
        ans[query[i].id] = now;
    }
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}