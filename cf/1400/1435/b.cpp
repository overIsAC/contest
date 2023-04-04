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
const int N = 3 + 500;

int n, m, a[N][N], b[N][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> a[i][j];
                mp[a[i][j]] = i;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> b[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            int p = mp[b[1][i]];
            for (int j = 1; j <= m; ++j) {
                cout << a[p][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}