#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 3 + 1e6;

int n;
PII a[N];
vector<PII> u, v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].second;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i].first < a[i].second) {
            u.push_back(a[i]);
        } else {
            v.push_back({a[i].second, a[i].first});
        }
    }
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());

    LL ans = 0;
    int mx = -1e9;
    for (int i = 0, j = 0; i < u.size(); ++i) {
        while (j < v.size() && u[i].first >= v[j].first) {
            mx = max(mx, v[j].second);
            ++j;
        }
        ans = max<LL>(ans, min(mx, u[i].second) - u[i].first);
    }

    swap(u, v);
    mx = -1e9;

    for (int i = 0, j = 0; i < u.size(); ++i) {
        while (j < v.size() && u[i].first >= v[j].first) {
            mx = max(mx, v[j].second);
            ++j;
        }
        ans = max<LL>(ans, min(mx, u[i].second) - u[i].first);
    }

    ans = -2LL * ans;

    for (int i = 1; i <= n; ++i) {
        ans += abs(a[i].first - a[i].second);
    }

    cout << ans << endl;

    return 0;
}