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
    int T;
    cin >> T;
    while (T--) {
        string s;
        int k;
        cin >> s >> k;
        int n = s.size();
        s = ' ' + s;
        vector<vector<int>> nxt(n + 2, vector<int>(10));
        for (int i = n; i > 0; --i) {
            for (int j = 0; j <= 9; ++j) {
                nxt[i][j] = nxt[i + 1][j];
            }
            nxt[i][s[i] - '0'] = i;
        }
        string ans;
        for (int i = 1; i <= n; ++i) {
            int down = ans.empty() ? 1 : 0;
            int v = 1111;
            for (int j = down; j <= s[i - 1] - '0'; ++j) {
                
            }
        }
    }
    return 0;
}