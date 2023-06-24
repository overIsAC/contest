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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 222;
const int M = 64;

LL n;
int m;
string s[N];

struct Mat {
    int a[M][M];
    Mat() {
        memset(a, 0, sizeof(a));
    }
    Mat operator*(const Mat &other) const {
        Mat ans;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                for (int k = 0; k < M; ++k) {
                    ans.a[i][j] = (ans.a[i][j] + (LL)a[i][k] * other.a[k][j]) % mod;
                }
            }
        }
        return ans;
    }
    Mat operator^(LL n) const {
        Mat ans, q = *this;
        for (int i = 0; i < M; ++i) {
            ans.a[i][i] = 1;
        }
        while (n) {
            if (n & 1) {
                ans = ans * q;
            }
            q = q * q;
            n >>= 1;
        }
        return ans;
    }
} a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
        for (auto &j : s[i]) {
            if (j == 'a') {
                j = 0;
            } else {
                j = 1;
            }
        }
    }
    auto f = [&](int x, int y) -> bool {
        string u, v;
        for (int i = 5; i >= 0; --i) {
            u += (char)(x >> i & 1);
            v += (char)(y >> i & 1);
        }
        if (u.substr(1) != v.substr(0, 5)) {
            return 0;
        }
        u += v.back();
        for (int i = 0; i < m; ++i) {
            if (u.find(s[i]) != string::npos) {
                return 0;
            }
        }
        return 1;
    };
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            a.a[i][j] = f(i, j);
        }
    }

    if (n <= 6) {
        int ans = 0;
        for (int i = 0; i < 1 << n; ++i) {
            string t;
            for (int j = 0; j < n; ++j) {
                t += (char)(i >> j & 1);
            }
            int ok = 1;
            for (int i = 0; i < m; ++i) {
                if (t.find(s[i]) != string::npos) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                ans += 1;
            }
        }
        cout << ans << endl;
        return 0;
    }

    a = a ^ (n - 6);

    LL ans = 0;
    for (int i = 0; i < M; ++i) {
        string t;
        for (int j = 5; j >= 0; --j) {
            t += (char)(i >> j & 1);
        }
        int ok = 1;
        for (int i = 0; i < m; ++i) {
            if (t.find(s[i]) != string::npos) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            for (int j = 0; j < M; ++j) {
                ans += a.a[i][j];
            }
        }
    }

    ans %= mod;

    cout << ans << endl;

    return 0;
}