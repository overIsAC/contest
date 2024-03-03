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

void solve() {
    char c;
    int n;
    cin >> n >> c;
    map<char, vector<char>> mp;
    for (int i = 1; i <= 2 * n; ++i) {
        string s;
        cin >> s;
        mp[s[1]].push_back(s[0]);
    }
    for (auto& [u, v] : mp) {
        sort(v.begin(), v.end());
    }
    vector<pair<string, string>> ans;
    vector<string> t;
    for (auto& [u, v] : mp) {
        if (u == c) {
            continue;
        }
        if (v.size() % 2) {
            t.push_back(string(1, u) + v.back());
            v.pop_back();
        }
        for (int i = 0; i < v.size(); i += 2) {
            ans.push_back({string(1, u) + v[i], string(1, u) + v[i + 1]});
        }
    }
    if (t.size() > mp[c].size()) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    while (t.size()) {
        ans.push_back({t.back(), string(1, c) + mp[c].back()});
        mp[c].pop_back();
        t.pop_back();
    }
    while (mp[c].size()) {
        string u = string(1, c) + mp[c].back();
        mp[c].pop_back();
        string v = string(1, c) + mp[c].back();
        mp[c].pop_back();
        ans.push_back({v, u});
    }
    for (auto& [u, v] : ans) {
        swap(u[0], u[1]);
        swap(v[0], v[1]);
        cout << u << ' ' << v << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}