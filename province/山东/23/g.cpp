#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 3 + 1e5;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        map<int, vector<int> > mp;
        for (int i = 1; i <= n; ++i) {
            mp[a[i] - i].push_back(a[i]);
        }
        LL ans = 0;
        for (auto& [x, y] : mp) {
            sort(y.begin(), y.end());
            while (y.size() > 1) {
                LL cnt = y.back();
                y.pop_back();
                cnt += y.back();
                y.pop_back();
                if (cnt >= 0) {
                    ans += cnt;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}