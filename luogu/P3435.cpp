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
const int N = 3 + 1e6;

int n;
char s[N];
int ne[N];
int fa[N];

int main() {
    cin >> n;
    cin >> s + 1;
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j && s[j + 1] != s[i]) {
            j = ne[j];
        }
        if (s[j + 1] == s[i]) {
            ++j;
        }
        ne[i] = j;

        fa[i] = j;
        if (fa[i] && fa[fa[i]]) {
            fa[i] = fa[fa[i]];
        }
    }

    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        int p = fa[i];
        if (p && (i - p) * 2 >= i) {
            ans += i - p;
        }
    }
    cout << ans << endl;
    return 0;
}