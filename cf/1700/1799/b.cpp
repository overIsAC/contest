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

PII a[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int one = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
            if (a[i].first == 1) {
                ++one;
            }
        }
        if (one) {
            if (one == n) {
                cout << 0 << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }
        sort(a + 1, a + n + 1);
        vector<PII> ans;
        while (a[1].first != a[n].first) {
            ans.push_back({a[n].second, a[1].second});
            a[n].first = (a[n].first + a[1].first - 1) / a[1].first;
            sort(a + 1, a + n + 1);
        }
        cout << ans.size() << endl;
        for (auto &i : ans) {
            cout << i.first << ' ' << i.second << endl;
        }
    }
    return 0;
}