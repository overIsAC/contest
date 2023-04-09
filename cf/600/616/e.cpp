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

const LL inv2 = (mod + 1) / 2;

struct Int {
    LL value;
    void norm() {
        value %= mod;
        if (value < 0) {
            value += mod;
        }
    }
    Int(LL value = 0) {
        this->value = value;
        norm();
    }
    Int operator+(const Int& other) const {
        return value + other.value;
    }
    Int operator-(const Int& other) const {
        return value - other.value;
    }
    Int operator*(const Int& other) const {
        return value * other.value;
    }
    Int& operator+=(const Int& other) {
        value += other.value;
        norm();
        return *this;
    }
    Int& operator-=(const Int& other) {
        value -= other.value;
        norm();
        return *this;
    }
    Int& operator*=(const Int& other) {
        value *= other.value;
        norm();
        return *this;
    }
    friend istream& operator>>(istream& in, Int& object) {
        in >> object.value;
        object.norm();
        return in;
    }
    friend ostream& operator<<(ostream& out, Int& object) {
        object.norm();
        out << object.value;
        return out;
    }
};

LL n, m;

int main() {
    cin >> n >> m;
    Int ans;
    for (LL l = 1, r = 1; l <= min(n, m); l = r + 1) {
        r = min(m, n / (n / l));
        ans -= Int(l + r) * (r - l + 1) * inv2 * (n / r);
        ans += (Int)n * (r - l + 1);
    }
    db("");
    if (n < m) {
        ans += (Int)n * (m - n);
    }
    cout << ans << endl;
    return 0;
}