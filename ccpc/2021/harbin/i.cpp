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
        vector<int> ve(33);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 31; ++j) {
                ve[j] += a[i] >> j & 1;
            }
        }
        LL ans = 0;
        while (ve.size()) {
            for (int i = 0; i + 1 < ve.size(); ++i) {
                if (ve[i] >= ve[i + 1]) {
                    continue;
                }
                int g = ve[i + 1] - ve[i];
                int v = (g + 2) / 3;
                ve[i + 1] -= v;
                ve[i] += v * 2;
            }
            while (ve.size() && ve.back() == 0) {
                ve.pop_back();
            }
            if (ve.size()) {
                int g = *min_element(ve.begin(), ve.end());
                ans += g;
                for (auto& i : ve) {
                    i -= g;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}