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
const int N = 3 + 2e5;

int n, m;
char s[N], t[N];
int ok[N];

int main() {
    cin >> n >> m;
    cin >> s + 1;
    cin >> t + 1;
    for (int i = 1; i + m - 1 <= n; ++i) {
        int equal = 1;
        for (int j = 0; j < m; ++j) {
            if (s[i + j] != t[j + 1]) {
                equal = 0;
                break;
            }
        }
        if (equal) {
            for (int j = 0; j < m; ++j) {
                ok[i + j] = equal;
            }
        }
    }

    for (int i = 1; i + m - 1 <= n; ++i) {
        int valid = 1;
        for (int j = 0; j < m; ++j) {
            if (ok[i + j]) {
                continue;
            }
            if (s[i + j] != t[j + 1]) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            for (int j = 0; j < m; ++j) {
                ok[i + j] = 1;
            }
        }
    }

    for (int i = n - m + 1; i >= 1; --i) {
        int valid = 1;
        for (int j = 0; j < m; ++j) {
            if (ok[i + j]) {
                continue;
            }
            if (s[i + j] != t[j + 1]) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            for (int j = 0; j < m; ++j) {
                ok[i + j] = 1;
            }
        }
    }

    if (accumulate(ok + 1, ok + n + 1, 0) == n) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}