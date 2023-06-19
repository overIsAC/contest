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
    string s, t;
    cin >> s >> t;
    vector<vector<int>> ne(s.size() + 1, vector<int>(26, s.size()));
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        ne[i] = ne[i + 1];
        ne[i][s[i] - 'a'] = i;
    }
    int ans = 1;
    int i = 0, j = 0;
    while (j < t.size()) {
        if (ne[i][t[j] - 'a'] == s.size()) {
            ++ans;
            i = ne[0][t[j] - 'a'] + 1;
        } else {
            i = ne[i][t[j] - 'a'] + 1;
        }
        ++j;
    }
    cout << ans << endl;
    return 0;
}