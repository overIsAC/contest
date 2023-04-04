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
const int N = 3 + 1e6;

string ans;
int cnt;
string a, b;

void dfs(int p, int lead, int mx, int mn, int limitLower, int limitUpper, string now) {
    if (mx != -100 && mn != 100 && cnt <= mx - mn) {
        return;
    }
    if (!limitLower && !limitUpper) {
        cnt = mx - mn;
        while (p >= 0) {
            now += now.back();
            --p;
        }
        ans = now;
        return;
    }
    if (p == -1) {
        cnt = mx - mn;
        ans = now;
        return;
    }
    char lower = limitLower ? a[p] : '0';
    char upper = limitUpper ? b[p] : '9';
    for (char i = lower; i <= upper; ++i) {
        if (lead && i == '0') {
            dfs(p - 1, lead, mx, mn, limitLower && i == a[p], limitUpper && i == b[p], now);
        } else {
            dfs(p - 1, 0, max(mx, i - '0'), min(mn, i - '0'), limitLower && i == a[p], limitUpper && i == b[p], now + i);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL l, r;
        cin >> l >> r;
        a = to_string(l);
        b = to_string(r);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (a.size() < b.size()) {
            a += '0';
        }
        cnt = 100;
        dfs(a.size() - 1, 1, -100, 100, 1, 1, "");
        cout << ans << endl;
    }
    return 0;
}

/*
100 1000
12312321 123123123321

*/