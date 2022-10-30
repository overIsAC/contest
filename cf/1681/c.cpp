#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m, a[N], b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        vector<PII> ans;
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (a[i] > a[j] || b[i] > b[j]) {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                    ans.push_back({i, j});
                }
                if (a[i] > a[j] || b[i] > b[j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }
        if (!ok) {
            cout << -1 << endl;
        } else {
            cout << ans.size() << endl;
            for (auto &i : ans) {
                cout << i.first << ' ' << i.second << endl;
            }
        }
    }
    return 0;
}