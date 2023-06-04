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

int n, m;

/*

()))()()))
*/
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (n % 2) {
            for (int i = n; i >= 1; i -= 2) {
                for (int j = 1; j <= m; ++j) {
                    cout << (i - 1) * m + j << ' ';
                }
                cout << endl;
            }
            for (int i = n - 1; i >= 1; i -= 2) {
                for (int j = 1; j <= m; ++j) {
                    cout << (i - 1) * m + j << ' ';
                }
                cout << endl;
            }
        } else {
            for (int i = n - 1; i >= 1; i -= 2) {
                for (int j = 1; j <= m; ++j) {
                    cout << (i - 1) * m + j << ' ';
                }
                cout << endl;
            }
            for (int i = n; i >= 1; i -= 2) {
                for (int j = 1; j <= m; ++j) {
                    cout << (i - 1) * m + j << ' ';
                }
                cout << endl;
            }
        }
    }
    return 0;
}