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
    cin >> n;
    n *= 2;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = 12312332;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            vector<int> b;
            for (int k = 1; k <= n; ++k) {
                if (i == k || j == k) {
                    continue;
                }
                b.push_back(a[k]);
            }
            sort(b.begin(), b.end());
            int temp = 0;
            for (int i = 0; i < b.size(); i += 2) {
                temp += b[i + 1] - b[i];
            }
            ans = min(ans, temp);
        }
    }
    cout << ans << endl;
    return 0;
}