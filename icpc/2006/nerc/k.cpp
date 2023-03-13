#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    ifstream cin("kickdown.in");
    ofstream cout("kickdown.out");
    string s, t;
    cin >> s >> t;
    int ans = 1e9;

    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            bool ok = true;
            for (int k = 0; k < min(s.size() + i, t.size() + j); ++k) {
                if (k < i || k < j) {
                    continue;
                }
                if (k >= s.size() + i || k >= t.size() + j) {
                    continue;
                }
                if (s[k - i] + t[k - j] - '0' - '0' > 3) {
                    ok = false;
                }
            }
            if (ok) {
                ans = min<int>(ans, max(s.size() + i, t.size() + j));
            }
        }
    }
    cout << ans << endl;
    return 0;
}