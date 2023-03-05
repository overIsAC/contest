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
const int N = 3 + 3e5;

int n, m;
int a[N], b[N];
vector<int> c[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }

    for (int i = n; i; --i) {
        c[a[i]].push_back(i);
    }

    int p = 0;
    for (int i = 1; i <= m; ++i) {
        int ans = 0;
        for (int j = 1; j <= 50; ++j) {
            auto& ve = c[j];
            if (ve.empty() || ve.back() > c[b[i]].back())
                continue;
            int l = 0, r = ve.size() - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (ve[mid] < c[b[i]].back()) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans += c[j].size() - r;
        }
        c[b[i]].back() = p--;
        cout << ans << ' ';
    }

    return 0;
}