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

string ans;
char s[N][N], t[N][N];
int n, q;

void getAnswer() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i][j] == 'O') {
                ans += t[i][j];
            }
        }
    }
}

char temp[N][N];

void rot() {
    memcpy(temp, s, sizeof(s));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            s[i][j] = temp[n - j + 1][i];
        }
    }
}

void palindrome() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n / 2; ++j) {
            swap(s[i][j], s[i][n - j + 1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] + 1;
    }
    getAnswer();
    while (q--) {
        int x;
        cin >> x;
        if (x <= 3) {
            for (int i = 1; i <= x; ++i) {
                rot();
            }
        } else if (x == 4) {
            palindrome();
        }
        getAnswer();
    }
    cout << ans << endl;

    return 0;
}