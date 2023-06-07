#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 3e5;

int n, m, a[N];
PII b[N], c[N];
LL dp[N];

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
        cin >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> b[i].first >> b[i].second;
        }
        sort(b + 1, b + m + 1);
        int t = 0, r = 0;
        for (int i = 1; i <= m; ++i) {
            if (r >= b[i].second) {
                continue;
            }
            c[++t] = b[i];
            r = b[i].second;
        }

    }

    return 0;
}