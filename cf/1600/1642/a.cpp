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

int main() {
    int T;
    cin >> T;
    while (T--) {
        PII a[3];
        for (int i = 0; i < 3; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a + 3,
             [&](const PII& a, const PII& b) { return a.second < b.second; });
        if (a[2].second == a[1].second) {
            cout << abs(a[2].first - a[1].first) << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}