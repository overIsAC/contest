#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<PII> a(n);
        for (auto &i : a) {
            cin >> i.first >> i.second;
        }
        LL ans = 0;
        sort(a.begin(), a.end());
        for (int l = 0, r = n - 1; l < r;) {
            int t = min(a[l].second, a[r].second);
            ans += (LL)t * (a[r].first - a[l].first);
            a[l].second -= t;
            a[r].second -= t;
            if (!a[l].second) {
                ++l;
            }
            if (!a[r].second) {
                --r;
            }
        }
        cout << ans << endl;
    }

    return 0;
}