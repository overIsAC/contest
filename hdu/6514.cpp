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

int p, q;
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m) {
        vector<vector<int>> pre1(n + 2, vector<int>(m + 2));
        vector<vector<int>> pre2(n + 2, vector<int>(m + 2));

        cin >> p;
        while (p--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ++pre1[x1][y1];
            --pre1[x1][y2 + 1];
            --pre1[x2 + 1][y1];
            ++pre1[x2 + 1][y2 + 1];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                pre1[i][j] += pre1[i - 1][j] + pre1[i][j - 1] - pre1[i - 1][j - 1];
                if (pre1[i][j]) {
                    ++pre2[i][j];
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                pre2[i][j] += pre2[i - 1][j] + pre2[i][j - 1] - pre2[i - 1][j - 1];
            }
        }

        cin >> q;
        while (q--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if ((x2 - x1 + 1) * (y2 - y1 + 1) == pre2[x2][y2] - pre2[x1 - 1][y2] - pre2[x2][y1 - 1] + pre2[x1 - 1][y1 - 1]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }


    return 0;
}