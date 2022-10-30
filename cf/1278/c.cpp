#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N];
int pre[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n * 2; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n * 2; ++i) {
            if (a[i] == 2) a[i] = -1;
            pre[i] = pre[i - 1] + a[i];
        }
        map<int, int> mp;
        int ans = n * 2;
        if (pre[2 * n] == 0) ans = 0;
        mp[0] = 1;
        for (int i = 1; i <= n * 2; ++i) {
            if (i <= n) mp[pre[i]] = i + 1; 
            if (i >= n && mp.count(pre[i] - pre[n * 2]))
                ans = min(ans, i - mp[pre[i] - pre[n * 2]] + 1);
        }
        cout << ans << endl;
    }
    return 0;
}