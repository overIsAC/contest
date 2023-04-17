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

int n;
char s[N];
int pre[N];

int main() {
    cin >> n;
    cin >> s + 1;
    int ans = 0;
    map<int, int> mp;
    mp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1];
        if (s[i] == '0') {
            --pre[i];
        } else {
            pre[i] += 1;
        }
        if (mp.count(pre[i])) {
            ans = max(ans, i - mp[pre[i]]);
        } else {
            mp[pre[i]] = i;
        }
    }
    cout << ans << endl;
    return 0;
}