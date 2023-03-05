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
const int N = 3 + 2e5;

int n;
LL k, x;
LL a[N];
pair<LL, LL> b[N];
int t;

int main() {
    cin >> n >> k >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    b[++t] = {a[1], a[1]};
    for (int i = 2; i <= n; ++i) {
        if (b[t].second + x >= a[i]) {
            b[t].second = a[i];
        } else {
            b[++t] = {a[i], a[i]};
        }
    }
    vector<LL> c;
    for (int i = 1; i < t; ++i) {
        c.push_back(b[i + 1].first - b[i].second);
    }
    LL ans = t;
    sort(c.begin(), c.end(), greater<LL>());
    while (c.size()) {
        LL v = c.back();
        c.pop_back();
        LL o = (v + x - 1) / x - 1;
        if (o <= k) {
            k -= o;
            --ans;
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}