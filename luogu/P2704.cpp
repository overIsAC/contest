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
const int N = 3 + 1e5;

vector<int> st1, st2[1 << 10], st3[1 << 10][1 << 10];
int n, m;
int dp[2][1 << 10][1 << 10];
char s[105][15];
int cnt[1 << 10];

int get(int p) {
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        ans |= (s[p][i] == 'P') << i;
    }
    return ans;
}

int f(int x) {
    int ans = 0;
    while (x) {
        ans += x % 2;
        x /= 2;
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < 1 << m; ++i) {
        if (i & (i << 1)) {
            continue;
        }
        if (i & (i << 2)) {
            continue;
        }
        st1.push_back(i);
        cnt[i] = f(i);
    }
    for (auto& i : st1) {
        for (auto& j : st1) {
            if (i & j) {
                continue;
            }
            st2[i].push_back(j);
        }
    }
    for (auto& i : st1) {
        for (auto& j : st2[i]) {
            for (auto& k : st2[j]) {
                if (i & j) {
                    continue;
                }
                if (i & k) {
                    continue;
                }
                if (j & k) {
                    continue;
                }
                st3[i][j].push_back(k);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }

    int u = get(1), v = get(2), w;

    memset(dp, -0x3f, sizeof(dp));

    for (auto& i : st1) {
        if ((u | i) != u) {
            continue;
        }
        for (auto& j : st2[i]) {
            if ((v | j) != v) {
                continue;
            }
            dp[0][j][i] = max(dp[0][j][i], cnt[i] + cnt[j]);
        }
    }

    int p1 = 1, p2 = 0;
    for (int i = 3; i <= n; ++i) {
        u = get(i);
        v = get(i - 1);
        w = get(i - 2);
        memset(dp[p1], -0x3f, sizeof(dp[p1]));
        for (auto& j : st1) {
            if ((u | j) != u) {
                continue;
            }
            for (auto& k : st2[j]) {
                if ((v | k) != v) {
                    continue;
                }
                for (auto& q : st3[j][k]) {
                    if ((w | q) != w) {
                        continue;
                    }
                    dp[p1][j][k] = max(dp[p1][j][k], dp[p2][k][q] + cnt[j]);
                }
            }
        }
        p1 = (p1 + 1) % 2;
        p2 = (p2 + 1) % 2;
    }
    int ans = 0;
    if (n >= 2) {
        u = get(n);
        v = get(n - 1);
        for (int i : st1) {
            if ((u | i) != u) {
                continue;
            }
            for (int j : st2[i]) {
                if ((v | j) != v) {
                    continue;
                }
                ans = max(dp[p2][i][j], ans);
            }
        }
    } else {
        u = get(1);
        for (auto& i : st1) {
            if ((i | u) != u) {
                continue;
            }
            ans = max(ans, cnt[i]);
        }
    }
    cout << ans << endl;

    return 0;
}