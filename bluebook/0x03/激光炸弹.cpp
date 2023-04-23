#include <bits/stdc++.h>
using namespace std;

const int N = 3 + 5e3;

int pre[N][N];
int n, r;

int main() {
    cin >> n >> r;
    while (n--) {
        int x, y, v;
        cin >> x >> y >> v;
        ++x;
        ++y;
        pre[x][y] += v;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i + r - 1 < N; ++i) {
        for (int j = 1; j + r - 1 < N; ++j) {
            ans = max(ans, pre[i + r - 1][j + r - 1] - pre[i + r - 1][j - 1] - pre[i - 1][j + r - 1] + pre[i - 1][j - 1]);
        }
    }
    cout << ans << endl;

    return 0;
}