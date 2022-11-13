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
const int N = 3 + 2e5;

int n;
char s[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (m == 1) {
            if (n == 1) {
                cout << 1 << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }
        cout << (n - m + m - 2) / (m - 1) * 2 + 1 << endl;
    }
    return 0;
}