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
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<PII> a(n);
        for (auto& [i, j] : a) {
            cin >> i;
        }
        for (auto& [i, j] : a) {
            cin >> j;
            j = abs(j);
        }
        sort(a.begin(), a.end(), [](PII a, PII b) {
            return a.second < b.second;
        });
        int ok = 1;
        LL pre = 0;
        for (int i = 0; i < n; ++i) {
            pre += a[i].first;
            LL ti = pre / k;
            if (pre % k) {
                ++ti;
            }
            if (a[i].second <= ti - 1) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}