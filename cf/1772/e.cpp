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
const int N = 3 + 5e5;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int x = 0, y = 0, z = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != i && a[i] != n - i + 1) {
                ++z;
            } else if (a[i] != i) {
                ++x;
            } else if (a[i] != n - i + 1) {
                ++y;
            }
        }
        if (y >= x + z) {
            cout << "First\n";
        } else if (x > y + z) {
            cout << "Second\n";
        } else {
            cout << "Tie\n";
        }
    }
    return 0;
}