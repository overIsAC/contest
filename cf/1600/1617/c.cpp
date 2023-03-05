#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int mod = 7 + 1e9;
const int N = 3 + 1e5;

int n, a[N];
bool vis[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            vis[i] = false;
        }
        map<int, int> mp;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ++mp[a[i]];
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && mp.count(i)) {
                vis[i] = true;
                --mp[i];
                if (mp[i] == 0) mp.erase(i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            auto j = mp.begin();
            if (i * 2 < j->first) {
                ++ans;
            } else {
                ans = -1;
                break;
            }
            if (j->second == 1) {
                mp.erase(mp.begin());
            } else {
                --mp.begin()->second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}