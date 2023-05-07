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
const int N = 3 + 2e6;

int n, a[N];
char ans[N];
int fa[N];

int find(int p) {
    return p == fa[p] ? p : fa[p] = find(fa[p]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= 2 * n + 2; ++i) {
        cin >> a[i];
        fa[i] = i;
    }
    int c = 1, r = 1;
    for (int i = 2; i <= 2 * n + 2; ++i) {
        int v;
        if (r >= i) {
            v = min(r - i, a[2 * c - i]);
        } else {
            v = 1;
        }
        while (v < a[i]) {
            fa[find(i + v)] = find(i - v);
            ++v;
        }
        if (r < i + a[i]) {
            r = i + a[i];
            c = i;
        }
    }
    char cc = 'a';
    for (int i = 3; i <= 2 * n + 2; ++i) {
        if (i % 2 == 0) {
            continue;
        }
        if (!ans[find(i)]) {
            ans[find(i)] = cc++;
        }
        cout << ans[find(i)];
    }
    return 0;
}