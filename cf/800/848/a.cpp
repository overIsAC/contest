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

int main() {
    int k;
    cin >> k;
    string ans;
    for (char i = 'a'; i <= 'z', k; ++i) {
        int j;
        for (j = 2; (j - 1) * j / 2 <= k; ++j) {
            ;
        }
        --j;
        k -= (j - 1) * j / 2;
        ans += string(j, i);
    }
    if (ans.empty()) {
        ans = 'a';
    }
    cout << ans << endl;
    return 0;
}