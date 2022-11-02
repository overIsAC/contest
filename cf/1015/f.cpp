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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 233;

LL dp[N][N][2];
int n, m;
char s[N];
int nxt[N];

int main() {
    cin >> n >> s + 1;
    m = strlen(s + 1);
    for (int i = 2, j = 0; i <= m; ++i) {
        while (j && s[j + 1] != s[i]) {
            j = nxt[j];
        }
        if (s[j + 1] == s[i]) {
            ++j;
        }
        nxt[i] = j;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            
        }
    }

    return 0;
}