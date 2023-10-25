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
    int n;
    cin >> n;
    auto isP = [&](string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    };
    auto get = [&](int v) {
        string ans;
        while (v) {
            if (v % n > 9) {
                ans += v % n - 10 + 'A';
            } else {
                ans += v % n + '0';
            }
            v /= n;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    };
    for (int i = 1; i <= 300; ++i) {
        auto s = get(i * i);
        if (isP(s)) {
            cout << get(i) << ' ' << s << endl;
        }
    }
    return 0;
}