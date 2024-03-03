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

struct Node {
    int x, y;
} a[N];

int n;
int stk[N], top;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y;
    }

    sort(a + 1, a + n + 1, [&](Node& a, Node& b) {
        return a.x < b.x;
    });

    int l = 0, r = 1e9;

    auto ok = [&](int v) {
        int maxY = -2e9, minY = 2e9;
        for (int i = 1, j = 1; i <= n; ++i) {
            while (a[i].x - a[j].x >= v) {
                minY = min(minY, a[j].y);
                maxY = max(maxY, a[j].y);
                ++j;
            }
            if (j > 1 && abs((LL)maxY - a[i].y) >= v) {
                return true;
            }
            if (j > 1 && abs((LL)minY - a[i].y) >= v) {
                return true;
            }
        }
        return false;
    };

    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (ok(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << r << endl;

    return 0;
}