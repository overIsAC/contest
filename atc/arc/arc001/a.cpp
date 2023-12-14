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
const int N = 3 + 1e5;

int n;
string s;

int main() {
    cin >> n >> s;
    int mn = 1e9, mx = 0;
    for (char i = '1'; i <= '4'; ++i) {
        int cnt = 0;
        for (auto& j : s) {
            cnt += i == j;
        }
        mn = min(mn, cnt);
        mx = max(mx, cnt);
    }
    cout << mx << ' ' << mn << endl;
    return 0;
}