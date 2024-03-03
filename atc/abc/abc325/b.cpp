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

int n, w, x;
int cnt[222];

int main() {
    cin >> n;
    while (n--) {
        cin >> w >> x;
        cnt[x] += w;
    }
    int ans = 0;
    for (int i = 0; i < 24; ++i) {
        int w = 0;
        for (int j = 0; j < 9; ++j) {
            w += cnt[(i + j) % 24];
        }
        ans = max(ans, w);
    }
    cout << ans << endl;
    return 0;
}