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

map<char, vector<char>> edge;
string s;
map<char, int> mp;
int vis[1111];
int ans, cnt, mx;

void dfs(char x) {
    if (vis[x]) {
        return;
    }
    cnt += mp[x];
    mx = max(mp[x], mx);
    vis[x] = 1;
    for (auto& y : edge[x]) {
        dfs(y);
    }
}

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        edge[s[i]].push_back(s[s.size() - 1 - i]);
        ++mp[s[i]];
    }
    for (auto& i : mp) {
        if (vis[i.first]) {
            continue;
        }
        cnt = 0;
        mx = 0;
        dfs(i.first);
        ans += cnt - mx;
    }
    cout << ans << endl;

    return 0;
}