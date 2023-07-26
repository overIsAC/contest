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
        string s, t;
        int n;
        cin >> n;
        cin >> s >> t;
        if (s == t) {
            cout << 0 << endl;
            continue;
        }
        reverse(t.begin(), t.end());
        if (s == t) {
            cout << 2 << endl;
            continue;
        }
        reverse(t.begin(), t.end());
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                ++ans1;
            }
        }
        if (ans1 % 2) {
            ans1 = ans1 * 2 - 1;
        } else {
            ans1 = ans1 * 2;
        }

        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            if (s[i] != t[j]) {
                ++ans2;
            }
        }

        db(ans2);
        if (ans2 % 2) {
            ans2 = ans2 * 2;
        } else {
            ans2 = ans2 * 2 - 1;
        }

        cout << min(ans1, ans2) << endl;
    }
    return 0;
}