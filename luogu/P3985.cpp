#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m, v[N], p[N];
int dp[102][102][102];
vector<int> b;

int main() {
    cin >> n >> m;
    int mn = 1e9;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> p[i];
        mn = min(mn, v[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i] - mn == 0) {
            for (int j = n; j >= 1; --j) {
                for (int k = n; k >= 0; --k) {
                    for (int q = n; q >= 0; --q) {
                        dp[j][k][q] = max(dp[j][k][q], dp[j - 1][k][q] + p[i]);
                    }
                }
            }
        } else if (v[i] - mn == 1) {
            for (int j = n; j >= 0; --j) {
                for (int k = n; k >= 1; --k) {
                    for (int q = n; q >= 0; --q) {
                        dp[j][k][q] = max(dp[j][k][q], dp[j][k - 1][q] + p[i]);
                    }
                }
            }
        } else if (v[i] - mn == 2) {
            for (int j = n; j >= 0; --j) {
                for (int k = n; k >= 0; --k) {
                    for (int q = n; q >= 1; --q) {
                        dp[j][k][q] = max(dp[j][k][q], dp[j][k][q - 1] + p[i]);
                    }
                }
            }
        } else {
            b.push_back(p[i]);
        }
    }
    sort(b.rbegin(), b.rend());

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (i * mn > m) {
            break;
        }
        for (int j = 0; i + j <= n; ++j) {
            if (i * mn + j * (mn + 1) > m) {
                break;
            }
            for (int k = 0; i + j + k <= n; ++k) {
                if (i * mn + j * (mn + 1) + k * (mn + 2) > m) {
                    break;
                }
                int z = dp[i][j][k];
                ans = max(ans, z);
                for (int q = 0; i + j + k + q + 1 <= n && q < b.size(); ++q) {
                    if (i * mn + j * (mn + 1) + k * (mn + 2) +
                            (q + 1) * (mn + 3) >
                        m) {
                        break;
                    }
                    z += b[q];
                    ans = max(ans, z);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}