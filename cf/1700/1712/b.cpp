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

int n, k, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int i = 1;
        if (n % 2) {
            cout << i << ' ';
            ++i;
        }
        for (; i <= n; i += 2) {
            cout << i + 1 << ' ' << i << ' ';
        }
        cout << endl;
    }

    return 0;
}