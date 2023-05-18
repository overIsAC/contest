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
const int N = 3 + 5e5;

struct Trie {
    int trie[N][26];
    bool end[N];
    int tot;
    Trie() {
        tot = 0;
        memset(trie, 0, sizeof(trie));
    }
    void insert(const char* s, const int& n) {
        int rt = 0;
        for (int i = 1; i <= n; ++i) {
            int c = s[i] - 'a';
            int& p = trie[rt][c];
            if (!p) {
                p = ++tot;
            }
            rt = p;
        }
        end[rt] = true;
    }
} a[2];

int n;
char s[N];
int dp[2][5005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i <= 1; ++i) {
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            cin >> s + 1;
            int m = strlen(s + 1);
            if (m > 5000) {
                continue;
            }
            a[i].insert(s, m);
        }
    }
    cin >> s + 1;
    n = strlen(s + 1);

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    dp[1][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 1; ++j) {
            int rt = 0;
            for (int k = i; k <= n; ++k) {
                int c = s[k] - 'a';
                int& p = a[j].trie[rt][c];
                if (!p) {
                    break;
                }
                rt = p;
                if (a[j].end[rt]) {
                    dp[j][k] = min(dp[j][k], dp[j ^ 1][i - 1] + 1);
                }
            }
        }
    }
    int ans = min(dp[1][n], dp[0][n]);
    if (ans > n) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}