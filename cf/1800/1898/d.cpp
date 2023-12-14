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
const int N = 3 + 1e5;

LL calc(vector<PII> a) {
    LL mn = 1e18, ans = -1e18;
    for (auto& [x, y] : a) {
        ans = max(ans, 2LL * (x - mn));
        mn = min<LL>(mn, y);
    }
    return ans;
}

LL calc2(vector<PII> a) {
    LL mn = 1e18, ans = -1e18;
    for (auto& [x, y] : a) {
        if (x >= y) {
            ans = max(ans, 2LL * (y - mn));
        }
        if (x <= y) {
            mn = min<LL>(mn, y);
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<PII> d(n);
    for (auto& [x, y] : d) {
        cin >> x;
    }
    for (auto& [x, y] : d) {
        cin >> y;
    }

    LL ans = 0;
    for (auto& [x, y] : d) {
        ans += abs(x - y);
    }
    vector<PII> a, b;
    for (auto& i : d) {
        if (i.first <= i.second) {
            a.push_back(i);
        }
        swap(i.first, i.second);
        if (i.first <= i.second) {
            b.push_back(i);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

#if 0
3
3
47326 358653 6958
3587 35863 59474
3
358653 47326 6958
3587 35863 59474
3
6958 47326 358653
3587 35863 59474
#endif
    // cout << ans << endl;
    // cout << endl;

    LL sum = ans;

    ans = max(ans, sum + calc(a));
    ans = max(ans, sum + calc(b));

    sort(d.begin(), d.end());
    ans = max(ans, sum + calc2(d));

    for (auto& i : d) {
        swap(i.first, i.second);
    }
    sort(d.begin(), d.end());
    ans = max(ans, sum + calc2(d));

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}