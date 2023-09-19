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

void solve() {
    int x, n;
    auto query = [&](int p) {
        cout << "? " << p << endl;
        cin >> x;
        return x;
    };

    cin >> n;
    int l = 0, r = n + 1;
    while (l + 2 < r) {
        int mid = l + r >> 1;
        int v1 = query(mid), v2 = query(mid + 1);
        if (v1 < v2) {
            r = mid + 1;
        } else {
            l = mid;
        }
    }
    cout << "! " << l + 1 << endl;
}

int main() {
    solve();
    return 0;
}