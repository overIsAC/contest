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

int n, a[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        vector<int> b;
        for (int j = 1; j <= n; ++j) {
            b.push_back(a[i][j]);
        }
        sort(b.begin(), b.end());
        for (int i = 1; i <= n; ++i) {
            if (b[i - 1] != i) {
                cout << "NO" << endl;
                return 0;
            }
        }
        b.clear();
        for (int j = 1; j <= n; ++j) {
            b.push_back(a[j][i]);
        }
        sort(b.begin(), b.end());
        for (int i = 1; i <= n; ++i) {
            if (b[i - 1] != i) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}