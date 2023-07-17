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

char s[N], t[N];
int q, n, m;
int ne[N];

void merge() {
    m = strlen(t + 1);
    for (int i = 2, j = 0; i <= m; ++i) {
        while (j && t[j + 1] != t[i]) {
            j = ne[j];
        }
        if (t[j + 1] == t[i]) {
            ++j;
        }
        ne[i] = j;
    }
    int p = max(1, n - m + 1);
    int ans = 0;
    for (int i = 0; p <= n; ++p) {
        while (i && s[p] != t[i + 1]) {
            i = ne[i];
        }
        if (s[p] == t[i + 1]) {
            ++i;
        }
        ans = i;
    }
    for (int i = ans + 1; i <= m; ++i) {
        s[++n] = t[i];
    }
    s[n + 1] = 0;
}

int main() {
    cin >> q;
    cin >> s + 1;
    n = strlen(s + 1);
    for (int i = 2; i <= q; ++i) {
        cin >> t + 1;
        merge();
    }
    cout << s + 1 << endl;
    return 0;
}