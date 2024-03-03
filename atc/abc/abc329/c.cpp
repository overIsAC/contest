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

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j + 1 < n && s[j] == s[j + 1]) {
            ++j;
        }
        mp[s[i]] = max(mp[s[i]], j - i + 1);
        i = j;
    }
    int ans = 0;
    for (auto [x, y] : mp) {
        ans += y;
    }
    cout << ans << endl;
    return 0;
}