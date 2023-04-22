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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2222;

struct Edge {
    int next, ver;
} e[N * N * 2];

int n;
char s[N][N];
int h1[N], h2[N], h3[N], h4[N];
int tot;

void add(int *h, int u, int v) {
    e[++tot].next = h[u];
    h[u] = tot;
    e[tot].ver = v;
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        h1[i] = h2[i] = h3[i] = h4[i] = 0;
    }
    tot = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i][j] == '-') continue;
            if (s[i][j] == 'P') {
                add(h1, i, j);
                add(h2, j, i);
            } else {
                add(h3, i, j);
                add(h4, j, i);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = h1[i]; j; j = e[j].next) {
            for (int k = h2[i]; k; k = e[k].next) {
                if (s[e[k].ver][e[j].ver] != 'P') {
                    puts("N");
                    return;
                }
            }
        }
        for (int j = h3[i]; j; j = e[j].next) {
            for (int k = h4[i]; k; k = e[k].next) {
                if (s[e[k].ver][e[j].ver] != 'Q') {
                    puts("N");
                    return;
                }
            }
        }
    }
    puts("T");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s[i] + 1);
        }
        solve();
    }
    return 0;
}