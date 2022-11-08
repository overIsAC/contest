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

int n, a[N];
map<int, int> mp;
map<int, int> mp2;
set<int> st;

void f(int a) {
    for (int i = 1, u = 0; a % i == 0; i *= 2, ++u) {
        for (int j = 1, v = 0; a / i % j == 0; j *= 3, ++v) {
            ++mp[a / i / j];
            mp2[a / i / j] += u + v;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        f(a[i]);
    }
    int ans = INT_MAX;
    for (auto& i : mp) {
        if (i.second == n) {
            ans = min(ans, mp2[i.first]);
        }
    }
    if (ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}