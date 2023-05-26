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
const int N = 3 + 3e5;

int n, a[N], k;

int ok(LL o) {
    multiset<int> u, v, w;
    LL sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        u.insert(a[i]);
        while (sum > o) {
            v.insert(*u.rbegin());
            sum -= *u.rbegin();
            u.erase(--u.end());
        }
    }
    if (sum <= o && u.size() >= k) {
        return 1;
    }
    LL cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += a[i];
        w.insert(a[i]);
        while (cnt > o) {
            cnt -= *w.rbegin();
            w.erase(--w.end());
        }
        if (v.size() && v.find(a[i]) != v.end()) {
            v.erase(v.find(a[i]));
        } else {
            u.erase(u.find(a[i]));
            sum -= a[i];
        }
        while (v.size() && sum + *v.begin() <= o) {
            sum += *v.begin();
            u.insert(*v.begin());
            v.erase(v.begin());
        }
        if (u.size() + w.size() >= k) {
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        LL L = *min_element(a + 1, a + n + 1), R = accumulate(a + 1, a + n + 1, 0LL);
        while (L < R) {
            LL mid = (L + R) / 2;
            if (ok(mid)) {
                R = mid;
            } else {
                L = mid + 1;
            }
        }
        cout << R << '\n';
    }
    return 0;
}