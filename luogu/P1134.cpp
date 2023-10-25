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

tuple<int, int> get(int v) {
    int a = 0;
    while (v % 2 == 0) {
        ++a;
        v /= 2;
    }
    while (v % 5 == 0) {
        --a;
        v /= 5;
    }
    return {a, v};
}

int main() {
    int n;
    cin >> n;
    int ans = 1;
    LL c = 0;
    for (int i = 1; i <= n; ++i) {
        auto [u, v] = get(i);
        ans = ans * v % 10;
        c += u;
    }
    LL q = 2;
    while (c) {
        if (c % 2) {
            ans = ans * q % 10;
        }
        q = q * q % 10;
        c /= 2; 
    }
    cout << ans << endl;
    return 0;
}