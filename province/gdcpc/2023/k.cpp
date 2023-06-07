#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

int n, m, k;
int a[11][11];
int ans;

void dfs(int now) {
    ans = min(ans, now);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j]) {
                continue;
            }
            if (i + 2 <= n && a[i + 1][j] && a[i + 2][j]) {
                a[i][j] = 1;
                a[i + 1][j] = 0;
                a[i + 2][j] = 0;
                dfs(now - 1);
                a[i][j] = 0;
                a[i + 1][j] = 1;
                a[i + 2][j] = 1;
            }
            if (j + 2 <= m && a[i][j + 1] && a[i][j + 2]) {
                a[i][j] = 1;
                a[i][j + 1] = 0;
                a[i][j + 2] = 0;
                dfs(now - 1);
                a[i][j] = 0;
                a[i][j + 1] = 1;
                a[i][j + 2] = 1;
            }
            if (i - 2 >= 1 && a[i - 1][j] && a[i - 2][j]) {
                a[i][j] = 1;
                a[i - 1][j] = 0;
                a[i - 2][j] = 0;
                dfs(now - 1);
                a[i][j] = 0;
                a[i - 1][j] = 1;
                a[i - 2][j] = 1;
            }
            if (j - 2 >= 1 && a[i][j - 1] && a[i][j - 2]) {
                a[i][j] = 1;
                a[i][j - 1] = 0;
                a[i][j - 2] = 0;
                dfs(now - 1);
                a[i][j] = 0;
                a[i][j - 1] = 1;
                a[i][j - 2] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= k; ++i) {
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
        }
        ans = 6;
        dfs(k);
        cout << ans << endl;
    }

    return 0;
}