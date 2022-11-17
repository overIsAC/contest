#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, m;
PII a[N];

int fa[N];
LL sz[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

int main() {
    cin >> n >> m;
    LL sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
        a[i].first = a[i].second % m;
        fa[i] = i;
        sum += a[i].second;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (a[i].first == a[(i + 1) % n].first) {
            fa[find(i)] = find((i + 1) % n);
        }
        if ((a[i].first + 1) % m == a[(i + 1) % n].first) {
            fa[find(i)] = find((i + 1) % n);
        }
    }
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, sz[find(i)] += a[i].second);
    }
    cout << sum - ans << endl;

    return 0;
}