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

int n;
vector<LL> a[N];
map<vector<LL>, int> mp[N];

vector<LL> get(string s) {
    vector<LL> ans;
    for (int i = 0; i < s.size(); i += 8) {
        int g = 0;
        for (int j = 7; j >= 0; --j) {
            if (i + j < (int)s.size()) {
                g = g * 10 + s[i + j] - '0';
            }
        }
        ans.push_back(g);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());

        a[i] = get(s);

        ++mp[a[i].size()][a[i]];
    }

    auto valid = [&](int size) -> int {
        if (size > 1001) {
            return 0;
        }
        return mp[size - 1].size() || mp[size].size() || mp[size + 1].size();
    };

    auto calc = [&](vector<LL> a, vector<LL> b) {
        vector<LL> t(a.size() + b.size() + 1);
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                t[i + j] += a[i] * b[j];
            }
        }
        LL g = 0;
        for (auto& i : t) {
            g += i;
            i = g % 100000000;
            g /= 100000000;
        }
        while (t.size() && t.back() == 0) {
            t.pop_back();
        }
        return t;
    };

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (!valid(a[i].size() + a[j].size())) {
                continue;
            }

            auto s = calc(a[i], a[j]);
            if (mp[s.size()].size() && mp[s.size()].count(s)) {
                int t = mp[s.size()][s];
                ans += t;
                if (i != j) {
                    ans += t;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}