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
    LL n;
    cin >> n;
    int ans = 1e9;
    string z[] = {"00", "25", "50", "75"};

    auto calc = [&](string s) -> int {
        string t = to_string(n);
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int ans = 0;
        int z = 0;
        for (auto &j : s) {
            for (int i = 0; i < t.size(); ++i) {
                if (t[i] == j) {
                    ans += i;
                    t.erase(t.begin() + i);
                    ++z;
                    break;
                }
            }
        }

        if (z != 2) {
            return 1e9;
        }

        t = s + t;
        if (t.back() == '0') {
            for (int i = t.size() - 1; i >= 2; --i) {
                if (t[i] > '0') {
                    return ans;
                }
                ++ans;
            }
            return 1e9;
        }
        return ans;
    };

    for (auto &i : z) {
        ans = min(ans, calc(i));
    }
    if (ans == 1e9) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}