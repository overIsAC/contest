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
const int N = 3 + 4e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l, r;
    cin >> n >> l >> r;
    while (n--) {
        int a;
        cin >> a;
        if (l <= a && a <= r) {
            cout << a << ' ';
            continue;
        }
        if (a < l) {
            cout << l << ' ';
            continue;
        }

        cout << r << ' ';
    }
    return 0;
}