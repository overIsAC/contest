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
const int N = 3 + 2e5;

int n, a[N], c;
vector<LL> prea, preb;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> c;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        prea.clear();
        preb.clear();
        for (int i = 1; i <= (n + 1) / 2; ++i) {
            prea.push_back(i + a[i]);
        }
        for (int i = n; i > (n + 1) / 2; --i) {
            preb.push_back(a[i] + n - i + 1);
        }
        sort(prea.begin(), prea.end());
        sort(preb.begin(), preb.end());
        for (int i = 1; i < prea.size(); ++i) {
            prea[i] += prea[i - 1];
        }
        for (int i = 1; i < preb.size(); ++i) {
            preb[i] += preb[i - 1];
        }
        int p = (int)preb.size() - 1;
        int ans = 0;
        for (int i = 0; i < prea.size(); ++i) {
            if (prea[i] <= c) {
                ans = max(ans, i + 1);
            }
            while (p >= 0 && preb[p] + prea[i] > c) {
                --p;
            }
            if (p >= 0 && preb[p] + prea[i] <= c) {
                ans = max(ans, i + 1 + p + 1);
            }
        }

        cout << ans << endl;
    }
    return 0;
}