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
const int N = 3 + 2e3;

string s;
int dp[N][N][26];
int n;

int dfs(int l, int r, char c) {
    int &v = dp[l][r][c];
    if (v != -1) {
        return v;
    }
    if (l == r) {
        if (s[r] - 'a' == c) return 0;
        if (s[r] - 'a' < c) return 1;
        return 2;
    }
    int v1 = dfs(l + 1, r, s[l] - 'a');
    int v2 = dfs(l, r - 1, s[r] - 'a');
    if (r - l + 1 & 1) {  // odd
        if (v1 == 1 || v2 == 1) {
            return v = 1;
        }
        if (v1 == 0 || v2 == 0) {
            if (v1 == 0 && s[l] - 'a' < c) return 1;
            if (v2 == 0 && s[r] - 'a' < c) return 1;
            if (v1 == 0 && s[l] - 'a' == c) return 0;
            if (v2 == 0 && s[r] - 'a' == c) return 0;
            return 2;
        }
        return v = 2;
    } else {
        if (v1 == 2 || v2 == 2) {
            return v = 2;
        }
        if (v1 == 0 && v2 == 0) {
            return v = 0;
        }
        return v = 1;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        n = s.size();
        if (n == 1) {
            cout << "Bob" << endl;
            continue;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 26; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        int v1 = dfs(1, n - 1, s[0] - 'a');
        int v2 = dfs(0, n - 2, s.back() - 'a');
        if (n & 1) {
            if (v1 == 1 || v2 == 1) {
                cout << "Alice" << endl;
            } else if (v1 == 0 || v2 == 0) {
                cout << "Draw" << endl;
            } else {
                cout << "Bob" << endl;
            }
        } else {
            if (v1 == 2 || v2 == 2) {
                cout << "Alice" << endl;
            } else if (v1 == 0 || v2 == 0) {
                cout << "Draw" << endl;
            } else {
                cout << "Bob" << endl;
            }
        }
    }
    return 0;
}