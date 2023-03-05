#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 5e5;

vector<int> a[N];
int n, m;
LL dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= min(m, n - i + 1); ++j) {
            int b;
            cin >> b;
            a[i].push_back(b);
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= min(m, n - i + 1); ++j) {
            dp[i + j] = min(dp[i + j], dp[i] + a[i][0] - a[i][j]);
        }
    }
    cout << dp[n + 1] << endl;
    return 0;
}