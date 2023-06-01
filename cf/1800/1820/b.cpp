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
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        LL ans = 0;
        if (count(s.begin(), s.end(), '1') == s.size()) {
            ans = (LL)s.size() * s.size();
        } else {
            int cnt = 0;
            for (int i = 0; i < 2 * s.size(); ++i) {
                if (s[i % s.size()] == '0') {
                    continue;
                }
                int j = i;
                while (j + 1 < s.size() * 2 && s[(j + 1) % s.size()] == '1') {
                    ++j;
                }
                cnt = max(cnt, j - i + 1);
                i = j;
            }
            for (int i = 1; i <= cnt; ++i) {
                ans = max(ans, (LL)i * (cnt - i + 1));
            }
        }
        cout << ans << endl;
    }
    return 0;
}