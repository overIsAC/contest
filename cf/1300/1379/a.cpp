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

int n;
string s;

int main() {
    const string t = "abacaba";
    int m = t.size();

    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        string ans = "";

        auto calc = [&](int p) -> string {
            if (p + m - 1 >= n) {
                return "";
            }
            string ans = s;
            for (int i = 0; i < m; ++i) {
                if (ans[i + p] == '?') {
                    ans[i + p] = t[i];
                }
                if (t[i] != ans[i + p]) {
                    return "";
                }
            }
            for (auto &i : ans) {
                if (i == '?') {
                    i = 'z';
                }
            }
            map<string, int> mp;
            for (int i = 0; i < ans.size(); ++i) {
                ++mp[ans.substr(i, m)];
            }
            if (mp[t] != 1) {
                return "";
            }
            return ans;
        };

        for (int i = 0; i < n; ++i) {
            auto r = calc(i);
            if (r.size()) {
                ans = r;
                break;
            }
        }
        if (ans.size()) {
            cout << "Yes" << endl;
            cout << ans << endl;
            continue;
        }
        cout << "No" << endl;
    }
    return 0;
}