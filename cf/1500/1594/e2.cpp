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

vector<LL> dp[N];

vector<LL> merge(const vector<LL>& a, const vector<LL>& u, const vector<LL>& v) {
    vector<LL> ans(6);
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if ((i - j + 6) % 3 == 0) {
                continue;
            }
            for (int k = 0; k < 6; ++k) {
                if ((i - k + 6) % 3 == 0) {
                    continue;
                }
                ans[i] = (ans[i] + u[j] * v[k]) % mod;
            }
        }
        ans[i] = a[i] * ans[i];
    }
    return ans;
}

int bin(LL v) {
    int ans = 0;
    while (v) {
        ans += 1;
        v /= 2;
    }
    return ans;
}

int main() {
    map<string, int> mp;
    mp["white"] = 0;
    mp["blue"] = 1;
    mp["red"] = 2;
    mp["yellow"] = 3;
    mp["green"] = 4;
    mp["orange"] = 5;

    dp[1] = {1, 1, 1, 1, 1, 1};
    for (int i = 2; i <= 60; ++i) {
        dp[i] = merge({1, 1, 1, 1, 1, 1}, dp[i - 1], dp[i - 1]);
    }

    int n, k;
    cin >> k >> n;
    map<LL, vector<LL>, greater<LL>> m1;
    map<LL, vector<vector<LL>>, greater<LL>> m2;
    set<LL> st;
    while (n--) {
        LL v;
        string s;
        cin >> v >> s;
        vector<LL> ve(6);
        ve[mp[s]] = 1;
        m1[v] = ve;
        st.insert(v);
    }

    for (auto i : st) {
        while (i /= 2) {
            if (m1.count(i)) {
                break;
            }
            m1[i] = {1, 1, 1, 1, 1, 1};
        }
    }

    while (true) {
        auto it = m1.begin();
        LL first = it->first;
        auto& vv = m2[first];
        int bb = bin(first);
        vector<LL> res;

        db(first);

        if (bb == k) {
            res = it->second;
        } else {
            while (vv.size() < 2) {
                vv.push_back(dp[k - bb]);
            }
            assert(vv.size() == 2);
            res = merge(it->second, vv[0], vv[1]);
        }
        if (first == 1) {
            cout << accumulate(res.begin(), res.end(), 0LL) % mod << endl;
            return 0;
        }
        m2[first / 2].push_back(res);
        m1.erase(first);
    }

    return 0;
}