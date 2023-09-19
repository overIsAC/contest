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

int f(int a, int b) {
    char s[111];
    sprintf(s, "%02d%02d", a, b);
    int ans = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '0') {
            ++ans;
        }
    }
    return ans;
}

int main() {
    string s;
    int a = 0, b = 0;
    int ans = 0;
    cin >> s;
    for (auto &i : s) {
        if (i == 'a') {
            ++a;
        } else {
            ++b;
        }
        ans += f(a, b);
    }
    cout << ans << endl;
    return 0;
}