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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    LL ans = 0;
    map<int, int> mp[2][26];
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        if (set<char>(s.begin(), s.end()).size() == 26) {
            continue;
        }
        int state = 0;
        int vis[26] = {};
        for (auto &i : s) {
            state ^= 1 << i - 'a';
            vis[i - 'a'] = 1;
        }
        db(state);
        for (int i = 0; i < 26; ++i) {
            if (!vis[i]) {
                int st = (1 << 26) - 1;
                st ^= 1 << i;
                if (mp[(s.size() & 1) ^ 1][i].count(state ^ st)) {
                    ans += mp[(s.size() & 1) ^ 1][i][state ^ st];
                }
                // cout << " get    " << ((s.size() & 1) ^ 1) << ' ' << i << ' ' << (state ^ st) << endl;
                // cout << i << ' ' << state << ' ' << (state ^ st) << ' ' << st << ' ' << s.size() << endl;
                mp[s.size() & 1][i][state] += 1;
                // cout << " add " << (s.size() & 1) << ' ' << i << ' ' << state << endl;
            } 
        }
        // cout << " ||| " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}