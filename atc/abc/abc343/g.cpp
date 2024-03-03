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
const int N = 3 + 2e5;

vector<int> getNext(string& s) {
    vector<int> ne(s.size() + 1);
    for (int i = 2, j = 0; i <= s.size(); ++i) {
        while (j && s[i - 1] != s[j]) {
            j = ne[j];
        }
        if (s[i - 1] == s[j]) {
            ++j;
        }
        ne[i] = j;
    }
    return ne;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& i : a) {
        cin >> i;
    }

    for (int i = 0; i < a.size(); ++i) {
        int have = 0;
        auto ne = getNext(a[i]);

        auto check = [&](string& s, string& t) {
            for (int i = 1, j = 0; i <= s.size(); ++i) {
                while (j && s[i - 1] != t[j]) {
                    j = ne[j];
                }
                if (s[i - 1] == t[j]) {
                    ++j;
                }
                if (j == t.size()) {
                    return 1;
                }
            }
            return 0;
        };

        for (int j = 0; j < a.size(); ++j) {
            if (i != j && check(a[j], a[i])) {
                have = 1;
                break;
            }
        }
        if (have) {
            a.erase(a.begin() + i);
            --i;
        }
    }
    vector<vector<int>> dp(1 << a.size(), vector<int>(a.size(), 1e9));

    vector<vector<int>> next(a.size());
    vector<vector<int>> _min(a.size(), vector<int>(a.size(), 1e9));

    for (int i = 0; i < a.size(); ++i) {
        next[i] = getNext(a[i]);
    }
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            auto f = [&](vector<int>& ne, string& s, string& t) {
                int i = 1, j = 0;
                for (; i <= s.size(); ++i) {
                    while (j && s[i - 1] != t[j]) {
                        j = ne[j];
                    }
                    if (s[i - 1] == t[j]) {
                        ++j;
                    }
                    if (i < s.size() && j == t.size()) {
                        j = ne[j];
                    }
                }
                return j;
            };
            _min[i][j] = f(next[j], a[i], a[j]);
        }
    }

    for (int i = 0; i < a.size(); ++i) {
        dp[1 << i][i] = a[i].size();
    }
    for (int i = 1; i < 1 << a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            if (i >> j & 1) {
                for (int k = 0; k < a.size(); ++k) {
                    if (!(i >> k & 1)) {
                        dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + (int)a[k].size() - _min[j][k]);
                    }
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < a.size(); ++i) {
        ans = min(ans, dp[(1 << a.size()) - 1][i]);
    }
    cout << ans << endl;

    return 0;
}