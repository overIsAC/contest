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
const int N = 3 + 2e5;

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int z = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            z += abs(a[i]);
        }
        if (z & 1) {
            cout << -1 << endl;
            continue;
        }
        vector<PII> ans;
        for (int i = 1; i <= n; ++i) {
            if (!a[i]) {
                ans.push_back({i, i});
                continue;
            }
            int j = i + 1;
            int sign = -1;
            while (a[j] == 0) {
                ++j;
                sign = -sign;
            }
            if (a[i] * sign * a[j] < 0) {
                ans.push_back({i, j});
            } else {
                if (sign < 0) {
                    ans.push_back({i, j - 1});
                    ans.push_back({j, j});
                } else {
                    ans.push_back({i, j - 2});
                    ans.push_back({j - 1, j});
                }
            }

            i = j;
        }
        cout << ans.size() << endl;
        for (auto &i : ans) {
            cout << i.first << ' ' << i.second << endl;
        }
    }
    return 0;
}