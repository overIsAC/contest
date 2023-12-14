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

string s[N];
int x[N], y[N];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'o') {
                ++x[i];
                ++y[j];
            }
        }
    }

    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'o') {
                ans += (LL)(x[i] - 1) * (y[j] - 1);
            }
        }
    }

    cout << ans << endl;

    return 0;
}