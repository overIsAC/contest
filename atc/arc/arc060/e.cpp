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

int n, x[N];
int L[N][20], R[N][20];
int len;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    cin >> len;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (x[i] - x[j] > len) {
            ++j;
        }
        L[i][0] = j;
    }
    L[1][0] = 0;
    for (int i = n, j = n; i >= 1; --i) {
        while (x[j] - x[i] > len) {
            --j;
        }
        R[i][0] = j;
    }
    R[n][0] = 0;
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j <= n; ++j) {
            L[j][i] = L[L[j][i - 1]][i - 1];
        }
        for (int j = n; j >= 1; --j) {
            R[j][i] = R[R[j][i - 1]][i - 1];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        if (a < b) {
            for (int j = 19; j >= 0; --j) {
                if (R[a][j] && R[a][j] <= b) {
                    ans += 1 << j;
                    a = R[a][j];
                }
            }
            if (a != b) {
                ++ans;
            }
        } else {
            for (int j = 19; j >= 0; --j) {
                if (L[a][j] && L[a][j] >= b) {
                    ans += 1 << j;
                    a = L[a][j];
                }
            }
            if (a != b) {
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}