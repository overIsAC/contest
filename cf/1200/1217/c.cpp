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

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector ne(n + 1, n);
    reverse(s.begin(), s.end());
    for (int i = n - 1; i >= 0; --i) {
        ne[i] = ne[i + 1];
        if (s[i] == '1') {
            ne[i] = i;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (ne[i] == n) {
            break;
        }
        if (ne[i] - i > 25) {
            continue;
        }
        int t = 0;
        int p = i;
        if (s[i] == '1') {
            t = 1;
        } else {
            t = 1 << ne[i] - i;
            p = ne[i];
        }
        while (true) {
            if (t == p - i + 1) {
                ++ans;
            } else {
                if (t > p - i + 1 && ne[p + 1] > i + t - 1) {
                    ++ans;
                }
            }

            if (ne[p + 1] == n) {
                break;
            }
            if (ne[p + 1] - i > 25) {
                break;
            }
            t += 1 << ne[p + 1] - i;
            p = ne[p + 1];
        }
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}