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
const int N = 3 + 1e3;

int n, m;
char s[N][N], t[N][N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    auto flip = [&]() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == 'X') {
                    s[i][j] = '.';
                } else {
                    s[i][j] = 'X';
                }
            }
        }
    };
    auto calc = [&]() {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans += s[i][j] != t[i][j];
            }
        }
        return ans;
    };

    int ans = calc();
    flip();
    if (ans < calc()) {
        flip();
    }
    for (int i = 0; i < n; ++i) {
        cout << s[i] << '\n';
    }

    return 0;
}