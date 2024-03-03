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
const int N = 3 + 1e3;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

LL pre[N][N];
int n, q;

int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i <= 1e3; ++i) {
            for (int j = 0; j <= 1e3; ++j) {
                pre[i][j] = 0;
            }
        }
        cin >> n >> q;
        while (n--) {
            int h, w;
            cin >> h >> w;
            pre[h][w] += h * w;
        }
        for (int i = 1; i <= 1e3; ++i) {
            for (int j = 1; j <= 1e3; ++j) {
                pre[i][j] += pre[i][j - 1];
            }
        }

        while (q--) {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
            LL ans = 0;
            for (int i = hs + 1; i < hb; ++i) {
                ans += pre[i][wb - 1] - pre[i][ws];
            }
            cout << ans << endl;
        }
    }
    return 0;
}