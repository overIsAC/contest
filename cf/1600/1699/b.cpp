#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int ans[55][55] = {0};
    for (int i = 1; i <= 54; ++i) {
        int o = 0;
        if (i % 4 == 1 || i % 4 == 2) {
            o = 1;
        }
        for (int j = 1; j <= 54; ++j) {
            ans[i][j] = o;
            if (j % 2 == 0) o ^= 1;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cout << ans[i + 1][j + 1] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}