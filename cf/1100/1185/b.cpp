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

string s, t;

void solve() {
    vector<PII> u, v;
    for (auto &i : s) {
        if (u.empty() || u.back().first != i) {
            u.push_back({i, 1});
        } else {
            ++u.back().second;
        }
    }
    for (auto &i : t) {
        if (v.empty() || v.back().first != i) {
            v.push_back({i, 1});
        } else {
            ++v.back().second;
        }
    }
    if (u.size() != v.size()) {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < u.size(); ++i) {
        if (u[i].first != v[i].first || u[i].second > v[i].second) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> s >> t;
        solve();
    }
    return 0;
}