#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod[2] = {7 + (int)1e9, 9 + (int)1e9};
const int N = 3 + 5e5;

char s[N];
ULL pre[2][N], suf[2][N];
ULL p[2][N];

void solve() {
    int n = strlen(s + 1);

    auto get1 = [&](int t, int l, int r) {
        return (pre[t][r] - pre[t][l - 1] * p[t][r - l + 1] % mod[t] + mod[t]) % mod[t];
    };
    auto get2 = [&](int t, int l, int r) {
        return (suf[t][l] - suf[t][r + 1] * p[t][r - l + 1] % mod[t] + mod[t]) % mod[t];
    };

    for (int j = 0; j <= 1; ++j) {
        p[j][0] = 1;
        for (int i = 1; i <= n; ++i) {
            p[j][i] = p[j][i - 1] * 131 % mod[j];
            pre[j][i] = (pre[j][i - 1] * 131 + s[i]) % mod[j];
        }
    }
    suf[0][n + 1] = 0;
    suf[1][n + 1] = 0;
    for (int j = 0; j <= 1; ++j) {
        for (int i = n; i >= 1; --i) {
            suf[j][i] = (suf[j][i + 1] * 131 + s[i]) % mod[j];
        }
    }
    int L = 1, R = n;
    while (L < R && s[L] == s[R]) {
        ++L;
        --R;
    }
    if (L >= R) {
        cout << "Yes\n";
        return;
    }

    for (int i = L; i < R; ++i) {
        auto u = (get2(0, L, i) * p[0][R - i] + get1(0, i + 1, R)) % mod[0];
        auto v = (get2(0, i + 1, R) * p[0][i - L + 1] + get1(0, L, i)) % mod[0];
        if (u == v) {
            cout << "Yes\n";
            return;
        }
        u = (get2(1, L, i) * p[1][R - i] + get1(1, i + 1, R)) % mod[1];
        v = (get2(1, i + 1, R) * p[1][i - L + 1] + get1(1, L, i)) % mod[1];
        if (u == v) {
            cout << "Yes\n";
            return;
        }
    }
    reverse(s + 1, s + n + 1);

    for (int j = 0; j <= 1; ++j) {
        p[j][0] = 1;
        for (int i = 1; i <= n; ++i) {
            p[j][i] = p[j][i - 1] * 131 % mod[j];
            pre[j][i] = (pre[j][i - 1] * 131 + s[i]) % mod[j];
        }
    }
    suf[0][n + 1] = 0;
    suf[1][n + 1] = 0;
    for (int j = 0; j <= 1; ++j) {
        for (int i = n; i >= 1; --i) {
            suf[j][i] = (suf[j][i + 1] * 131 + s[i]) % mod[j];
        }
    }

    for (int i = L; i < R; ++i) {
        auto u = (get2(0, L, i) * p[0][R - i] + get1(0, i + 1, R)) % mod[0];
        auto v = (get2(0, i + 1, R) * p[0][i - L + 1] + get1(0, L, i)) % mod[0];
        if (u == v) {
            cout << "Yes\n";
            return;
        }
        u = (get2(1, L, i) * p[1][R - i] + get1(1, i + 1, R)) % mod[1];
        v = (get2(1, i + 1, R) * p[1][i - L + 1] + get1(1, L, i)) % mod[1];
        if (u == v) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> s + 1;
        solve();
    }
    return 0;
}
