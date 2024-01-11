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

int n, a[N];
LL k;

mt19937 rnd(time(NULL));

int rand(int l, int r) {
    if (l > r) {
        return 0;
    }
    return rnd() % (r - l + 1) + l;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int mx = *max_element(a + 1, a + n + 1);

    LL d = (LL)mx * n - accumulate(a + 1, a + n + 1, 0LL);
    if (d <= k) {
        cout << mx + (k - d) / n << endl;
        return 0;
    }

    auto ok = [&](int z) {
        LL sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] <= z) {
                sum += z - a[i];
            } else {
                if (a[i] % z) {
                    sum += z - a[i] % z;
                }
            }
        }
        return sum <= k;
    };

    set<int> st;

    int ans = 1;
    if (d / n) {
        ans = d / n;
    }
    for (int i = 1; i <= 1000; ++i) {
        int v = rand(ans + 1, mx - 1);
        if (!v) {
            break;
        }
        if (ok(v)) {
            ans = v;
        }
        st.insert(v);
    }

    for (int i = mx - 1; i > ans; --i) {
        if (!st.count(i) && ok(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}