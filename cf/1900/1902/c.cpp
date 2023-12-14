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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    int mx = *max_element(a.begin(), a.end());
    int g = 0;
    for (int i = 0; i < n; ++i) {
        g = __gcd(mx - a[i], g);
    }

    if (!g) {
        cout << 1 << endl;
        return;
    }

    vector<int> v;
    for (int i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            v.push_back(i);
            v.push_back(g / i);
        }
    }

    set<int> st(a.begin(), a.end());

    LL ans = LLONG_MAX;

    auto calc = [&](int v) {
        LL t = 0;
        for (auto& i : a) {
            t += (mx - i) / v;
        }

        ans = min(ans, t + n);

        for (int z = mx - v; ans > t; z -= v) {
            t += 1;
            if (st.count(z)) {
                continue;
            }
            ans = min(ans, t);
        }
        return ans;
    };

    for (auto& i : v) {
        calc(i);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}