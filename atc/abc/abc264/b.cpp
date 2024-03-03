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

int main() {
    map<int, int> mp;
    string s = "atcoder";
    for (int i = 0; i < s.size(); ++i) {
        mp[s[i]] = i;
    }
    cin >> s;
    for (auto &i : s) {
        i = mp[i];
    }
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j + 1 < s.size(); ++j) {
            if (s[j] > s[j + 1]) {
                swap(s[j], s[j + 1]);
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}