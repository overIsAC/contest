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
const int N = 3 + 1e7;

int M;
int p[N];
vector<int> prime;

string f(int x, int y) {
    int sign = 1;
    if (x < 0) {
        sign = -sign;
        x = -x;
    }
    if (y < 0) {
        sign = -sign;
        y = -y;
    }
    int g = __gcd(x, y);
    x /= g;
    y /= g;
    if (x == 0) {
        y = 1;
    }

    string ans;
    if (sign < 0) {
        ans += '-';
    }

    if (y == 1) {
        ans += to_string(x);
    } else {
        ans += to_string(x) + "/" + to_string(y);
    }
    return ans;
}

PII getFrac(int a, int b) {
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    if (a == 0) {
        b = 1;
    }
    if (a < 0) {
        a = -a;
        b = -b;
    }
    return {a, b};
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a < 0) {
        a = -a;
        b = -b;
        c = -c;
    }
    if (b * b < 4 * a * c) {
        cout << "NO" << endl;
        return;
    }
    int det = b * b - 4 * a * c;
    int sq = sqrt(det);
    if (sq * sq == det) {
        cout << f(-b + sq, 2 * a) << endl;
        return;
    }

    if (b != 0) {
        cout << f(-b, 2 * a) << "+";
    }

    int x = 1, y = 2 * a;
    for (auto &p : prime) {
        if (p * p > det) {
            break;
        }
        while (det % (p * p) == 0) {
            x *= p;
            det /= p * p;
        }
    }
    PII pii = getFrac(x, y);
    x = pii.first;
    y = pii.second;
    if (x == y) {
        cout << "sqrt(" << f(det, 1) << ")" << endl;
        return;
    }
    if (x % y == 0) {
        cout << f(x, y) << "*sqrt(" << f(det, 1) << ")" << endl;
        return;
    }
    if (x == 1) {
        cout << "sqrt(" << f(det, 1) << ")/" << y << endl;
        return;
    }
    cout << x << "*sqrt(" << f(det, 1) << ")/" << y << endl;
}

int main() {
    for (int i = 2; i < N; ++i) {
        if (p[i]) {
            continue;
        }
        prime.push_back(i);
        for (int j = i + i; j < N; j += i) {
            p[j] = 1;
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T >> M;
    while (T--) {
        solve();
    }
    return 0;
}