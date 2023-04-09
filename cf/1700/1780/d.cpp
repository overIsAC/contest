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

int main() {
    int T;
    cin >> T;

    auto sub = [&](int v) {
        cout << "- " << v << endl;
        cin >> v;
        return v;
    };

    while (T--) {
        int n;
        cin >> n;
        int ans = 0;
        int i = 1, j;
        while (n) {
            j = sub(i);
            ans += 1 << (j - n + 1);
            i = 1 << (j - n + 1);
            --n;
        }
        cout << "! " << ans << endl;
    }
    return 0;
}