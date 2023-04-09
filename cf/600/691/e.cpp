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

template <int N>
struct Matrix {
    int a[N][N];
    Matrix() {
        memset(a, 0, sizeof(a));
    }
    Matrix operator*(const Matrix& other) const {
        Matrix ans;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    ans.a[i][j] = (ans.a[i][j] + (LL)a[i][k] * other.a[k][j]) % mod;
                }
            }
        }
        return ans;
    }
    Matrix operator*(LL n) const {
        Matrix ans, q = *this;
        for (int i = 0; i < N; ++i) {
            ans.a[i][i] = 1;
        }
        while (n > 0) {
            if (n & 1) {
                ans = ans * q;
            }
            q = q * q;
            n >>= 1;
        }
        return ans;
    }
};

LL k, a[N];
int n;
Matrix<100> x;

LL calc(LL v) {
    LL ans = 0;
    while (v) {
        ans += v % 2;
        v /= 2;
    }
    return ans;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (calc(a[i] ^ a[j]) % 3 == 0) {
                x.a[i][j] = 1;
            }
        }
    }
    x = x * (k - 1);
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += x.a[i][j];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}