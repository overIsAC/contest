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
    string s;
    cin >> s;
    int n = s.size();
    map<char, LL> mp1;
    map<pair<char, char>, LL> mp2;
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        for (auto [x, y] : mp1) {
            mp2[{x, s[i]}] += y;
        }
        ++mp1[s[i]];
    }
    for (auto [x, y] : mp1) {
        ans = max(ans, y);
    }
    for (auto [x, y] : mp2) {
        ans = max(ans, y);
    }
    cout << ans << endl;
    return 0;
}