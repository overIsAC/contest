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
const int N = 3 + 2e5;

int n;
PII a[N];
map<int, vector<PII>> mp;

LL dis(PII &a, PII &b) {
    return (LL)abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        mp[max(a[i].first, a[i].second)].push_back(a[i]);
    }
    mp[0].push_back({0, 0});
    map<int, LL> dp1, dp2;
    dp1[0] = 0;
    dp1[1] = 0;
    vector<PII> ve;

    for (auto &[x, y] : mp) {
        if (x == 0) {
            ve = y;
            continue;
        }
        sort(y.begin(), y.end(), [](PII &a, PII &b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        dp2[0] = 1e18;
        dp2[1] = 1e18;

        dp2[0] = min(dp2[0], dp1[0] + dis(*ve.begin(), *y.rbegin()) + dis(*y.rbegin(), *y.begin()));
        dp2[0] = min(dp2[0], dp1[1] + dis(*ve.rbegin(), *y.rbegin()) + dis(*y.rbegin(), *y.begin()));
        dp2[1] = min(dp2[1], dp1[0] + dis(*ve.begin(), *y.begin()) + dis(*y.rbegin(), *y.begin()));
        dp2[1] = min(dp2[1], dp1[1] + dis(*ve.rbegin(), *y.begin()) + dis(*y.rbegin(), *y.begin()));

        ve = y;

        swap(dp1, dp2);
    }

    cout << min(dp1[0], dp1[1]) << endl;

    return 0;
}