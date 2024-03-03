#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> rowA(n + 1, vector<int>(m + 1));
    vector<vector<int>> rowB(n + 1, vector<int>(m + 1));
    vector<vector<int>> colA(n + 1, vector<int>(m + 1));
    vector<vector<int>> colB(n + 1, vector<int>(m + 1));
    vector<string> s(n);
    for (auto& i : s) {
        cin >> i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'x') {
                ++rowA[i + 1][j + 1];
                ++colA[i + 1][j + 1];
            } else if (s[i][j] == 'o') {
                ++rowB[i + 1][j + 1];
                ++colB[i + 1][j + 1];
            }
        }
    }

    int ans = 1e9;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            rowA[i][j] += rowA[i - 1][j];
            rowB[i][j] += rowB[i - 1][j];
            colA[i][j] += colA[i][j - 1];
            colB[i][j] += colB[i][j - 1];

            if (i >= k && rowA[i][j] - rowA[i - k][j] == 0) {
                ans = min(ans, k - (rowB[i][j] - rowB[i - k][j]));
            }
            if (j >= k && colA[i][j] - colA[i][j - k] == 0) {
                ans = min(ans, k - (colB[i][j] - colB[i][j - k]));
            }
        }
    }

    if (ans == 1e9) {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}