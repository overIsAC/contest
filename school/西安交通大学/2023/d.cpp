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
const int N = 3 + 123;

int n, a[N], b[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    int minX = *min_element(a + 1, a + n + 1);
    int maxX = *max_element(a + 1, a + n + 1);
    int minY = *min_element(b + 1, b + n + 1);
    int maxY = *max_element(b + 1, b + n + 1);
    if (!(minX <= 0 && 0 <= maxX) && !(minY <= 0 && 0 <= maxY)) {
        cout << -1 << endl;
        return 0;
    }
    if ((maxX - minX + 1) * (maxY - minY + 1) != n) {
        cout << -1 << endl;
        return 0;
    }
    cout << maxX + maxY - minX - minY << endl;
    return 0;
}