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
    int n, m;
    cin >> n >> m;
    auto isP = [&](string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    };
    auto get = [&](int v, int n) {
        string ans;
        while (v) {
            ans += v % n + '0';
            v /= n;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    };
    for (int i = m + 1; n; ++i) {
        int c = 0;
        for (int j = 2; j <= 10; ++j) {
            if (isP(get(i, j))) {
                ++c;
            }
        }
        if (c >= 2) {
            --n;
            cout << i << endl;
        }
    }
    return 0;
}