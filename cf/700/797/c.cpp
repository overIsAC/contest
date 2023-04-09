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

int stk[N], top;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> vis(n);
    vis.push_back(vector<int>(26));
    for (int i = n - 1; i >= 0; --i) {
        vis[i] = vis[i + 1];
        vis[i][s[i] - 'a'] = 1;
    }
    string ans;
    for (int i = 0; i < n; ++i) {
        if (!top) {
            stk[++top] = s[i];
        } else {
            int flag = 0;
            for (int j = 0; j < stk[top] - 'a'; ++j) {
                if (vis[i][j]) {
                    flag = 1;
                }
            }
            if (flag) {
                stk[++top] = s[i];
            } else {
                ans += stk[top--];
                --i;
            }
        }
    }
    while (top) {
        ans += stk[top--];
    }
    cout << ans << endl;
    return 0;
}