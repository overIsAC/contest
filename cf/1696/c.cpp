#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m, k, a[N], b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        vector<pair<int, LL>> q, w;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            int u = a[i], v = 1;
            while (u % k == 0) {
                u /= k;
                v *= k;
            }
            if (q.empty() || q.back().first != u) {
                q.push_back({u, v});
            } else {
                q.back().second += v;
            }
        }
        cin >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> b[i];
            int u = b[i], v = 1;
            while (u % k == 0) {
                u /= k;
                v *= k;
            }
            if (w.empty() || w.back().first != u) {
                w.push_back({u, v});
            } else {
                w.back().second += v;
            }
        }
        cout << (q == w ? "Yes" : "No") << endl;
    }
    return 0;
}