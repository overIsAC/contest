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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e5;

LL c[77][77];

int main() {
    c[0][0] = 1;
    for (int i = 1; i < 77; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        LL x = 0, y = 0, z = 1;
        int cnt= 0;
        for (int i = n; i; i -= 2) {
            x += c[i - 1][i / 2 - 1];
            if (i / 2 >= 2) y += c[i - 2][i / 2 - 2];
            swap(x, y);
            ++cnt;
        }
        x %= mod;
        y %= mod;
        if (cnt & 1) swap(x, y);
        cout << x << ' ' << y << ' ' << z << endl;
    }
    return 0;
}