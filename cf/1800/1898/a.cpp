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

void solve() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    int cnt = 0;
    for (auto& i : s) {
        if (i == 'B') {
            ++cnt;
        }
    }
    if (cnt == k) {
        cout << 0 << endl;
        return;
    }
    char c = cnt > k ? 'A' : 'B';
    for (int i = 0; i < n; ++i) {
        if (cnt > k) {
            if (s[i] == 'B') {
                --cnt;
            }
        } else {
            if (s[i] == 'A') {
                ++cnt;
            }
        }
        if (cnt == k) {
            cout << 1 << endl;
            cout << i + 1 << ' ' << c << endl;
            return;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}