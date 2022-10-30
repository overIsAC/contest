#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];
map<int, int> mp;
vector<int> ve[N];
int ans[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            if (!mp[a[i]]) {
                mp[a[i]] = mp.size();
                ve[mp.size()].clear();
            }
            a[i] = mp[a[i]];
        }
        for (int i = 1; i <= n; ++i) {
            ve[a[i]].push_back(i);
        }
        bool flag = true;
        for (int i = 1; i <= mp.size(); ++i) {
            if (ve[i].size() == 1) {
                flag = false;
                break;
            }
        }
        if (flag == false) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 1; i <= mp.size(); ++i) {
            for (int j = 0; j < ve[i].size(); ++j) {
                ans[ve[i][j]] = ve[i][(j + 1) % ve[i].size()];
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}