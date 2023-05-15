#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    LL ans = 1e18;
    for (int i = 0; i < n; ++i) {
        LL cnt = 0, v = 0;
        for (int j = i + 1; j < n; ++j) {
            LL c = v / a[j] + 1;
            cnt += c;
            v = c * a[j];
        }
        v = 0;
        for (int j = i - 1; j >= 0; --j) {
            LL c = v / a[j] + 1;
            cnt += c;
            v = c * a[j];
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}