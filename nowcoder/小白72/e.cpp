#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
using LL = long long;

const int N = 3 + 1e5;

int n, m, k, Q;
PII a[N], b[N], c[N];
int oa[N], ob[N];
vector<int> ve[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> Q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; ++i) {
        oa[a[i].second] = i;
    }
    for (int i = 1; i <= m; ++i) {
        ob[b[i].second] = i;
    }
    for (int i = 1; i <= k; ++i) {
        int u, v;
        cin >> u >> v;
        ve[oa[u]].push_back(ob[v]);
    }

    for (int i = 1; i <= n; ++i) {
        sort(ve[i].begin(), ve[i].end());
    }

    auto calc = [&](LL v) -> LL {
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            int l = 1, r = m;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if ((LL)a[i].first * b[mid].first <= v) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            int p = upper_bound(ve[i].begin(), ve[i].end(), r) - ve[i].begin();
            if ((LL)a[i].first * b[r].first <= v) {
                ans += r;
                ans -= p;
            } else {
                break;
            }
        }
        return ans;
    };

    while (Q--) {
        LL k;
        cin >> k;
        LL l = 1, r = 1e12;

        while (l < r) {
            LL mid = (l + r) / 2;
            if (calc(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << r << endl;
    }
    return 0;
}