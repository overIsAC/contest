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

string s;

int get(int a, int b) {
    a -= '0';
    b -= '0';
    return a * 10 + b;
}

int main() {
    const int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> s;
    int ans = 111;
    for (char i = '0'; i <= '9'; ++i) {
        for (char j = '0'; j <= '9'; ++j) {
            for (char x = '0'; x <= '9'; ++x) {
                for (char y = '0'; y <= '9'; ++y) {
                    int m = get(i, j);
                    int d = get(x, y);
                    if (1 <= m && m <= 12 && 1 <= d && d <= month[m]) {
                        ans = min(ans, (i != s[0]) + (j != s[1]) + (x != s[3]) + (y != s[4]));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}