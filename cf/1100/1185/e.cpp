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
const int N = 3 + 2000;

int n, m;
char s[N][N];
char t[N][N];

void solve() {
    vector<PII> a[26];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] != '.') {
                a[s[i][j] - 'a'].push_back({i, j});
            }
        }
    }
    for (auto &i : a) {
        sort(i.begin(), i.end());
        if (i.size() <= 2) {
            continue;
        }
        if (i[1].first == i[0].first) {
            for (int j = 1; j < i.size(); ++j) {
                if (i[j].first != i[0].first) {
                    cout << "NO" << endl;
                    return;
                }
            }
        } else {
            for (int j = 1; j < i.size(); ++j) {
                if (i[j].second != i[0].second) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    vector<vector<int>> ans;
    for (int i = 0; i < 26; ++i) {
        if (a[i].size()) {
            ans.push_back({a[i][0].first, a[i][0].second, a[i].back().first, a[i].back().second});
        } else {
            for (int j = i + 1; j < 26; ++j) {
                if (a[j].size()) {
                    ans.push_back({a[j][0].first, a[j][0].second, a[j].back().first, a[j].back().second});
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            t[i][j] = '.';
        }
        t[i][m + 1] = 0;
    }
    for (int i = 0; i < ans.size(); ++i) {
        auto &v = ans[i];
        if (v[0] == v[2]) {
            for (int j = v[1]; j <= v[3]; ++j) {
                t[v[0]][j] = i + 'a';
            }
        } else {
            for (int j = v[0]; j <= v[2]; ++j) {
                t[j][v[1]] = i + 'a';
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] != t[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto &i : ans) {
        for (auto &j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> s[i] + 1;
        }
        solve();
    }
    return 0;
}