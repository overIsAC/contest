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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

map<LL, LL> mp;
LL n;

LL f(LL n) {
    if (!mp[n])
        return mp[n] = f(n / 2) + f(n / 3);
    return mp[n];
}

int main() {
    mp[0] = 1;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}