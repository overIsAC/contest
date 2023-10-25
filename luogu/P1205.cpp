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
const int N = 3 + 111;

char s[N][N], t[N][N];
int n;

void rev() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n/2; ++j) {
            swap(s[i][j], s[i][n - j + 1]);
        }
    }
}

void rot() {
    static char t[N][N];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            t[j][n - i + 1] = s[i][j];
        }
    }
    memcpy(s, t, sizeof(s));
}

int eq() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i][j] != t[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] + 1;
    }
    int ans = 7;
    if (eq()) {
        ans = min(ans, 6);
    }
    for (int i = 1; i <= 3; ++i) {
        rot();
        if (eq()) {
            ans = min(ans, i);
        }
    }
    rot();
    rev();
    if (eq()) {
        ans = min(ans, 4);
    }
    for (int i = 1; i <= 3; ++i) {
        rot();
        if (eq()) {
            ans = min(ans, 5);
        }
    }
    cout << ans << endl;
    return 0;
}