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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

map<LL, LL> mp;

long long f(long long x) {
    if (!mp.count(x)) mp[x] = f(x / 2) + f(x / 2 + x % 2);
    return mp[x];
}

int main() {
    mp[1] = 1;
    LL x;
    cin >> x;
    cout << f(x) << endl;
    return 0;
}