#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;

template <int N>
struct Matrix {
    int a[N][N];
    Matrix operator*(const Matrix<N> &other) const {
        auto &u = a;
        auto &v = other.a;
        Matrix ans = {};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    ans.a[i][j] = (ans.a[i][j] + (LL)u[i][k] * v[k][j]) % mod;
                }
            }
        }
        return ans;
    }
    Matrix operator^(int n) const {
        Matrix ans = {};
        Matrix q = *this;
        for (int i = 0; i < N; ++i) {
            ans.a[i][i] = 1;
        }
        while (n > 0) {
            if (n & 1) {
                ans = ans * q;
            }
            q = q * q;
            n /= 2;
        }
        return ans;
    }
};

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) {
            ans = ans * q % mod;
        }
        q = q * q % mod;
        n >>= 1;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k, l;
        cin >> n >> k >> l;
        if (k == 1) {
            cout << 0 << endl;
            continue;
        }
        if (k == 2) {
            cout << (LL)l * (l - 1) % mod << endl;
            continue;
        }
        Matrix<2> a;
        a.a[0][0] = l - 2;
        a.a[0][1] = l - 1;
        a.a[1][0] = 1;
        a.a[1][1] = 0;
        auto b = a ^ (k - 2);
        LL f1 = 0;
        LL f2 = (LL)l * (l - 1) % mod;
        LL ans = b.a[0][0] * f2 + b.a[0][1] * f1;
        ans = (ans % mod + mod) % mod;
        LL temp = (l - 1 + (LL)(l - 2) * (l - 2)) % mod;
        temp = (temp % mod + mod) % mod;
        ans = ans * qpow(temp, (LL)k * n - k) % mod;
        cout << ans << endl;
    }
    return 0;
}