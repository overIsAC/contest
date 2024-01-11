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

int t, n, a[N];

int main() {
    cin >> t >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> u, v;
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= 0) {
            u.push_back(-a[i]);
        } else {
            v.push_back(a[i]);
        }
    }
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());

    int ans = 0, l, r;
    for (int i = 0; i < u.size(); ++i) {
        if (u[i] <= t) {
            ans = max(ans, i + 1);
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] <= t) {
            ans = max(ans, i + 1);
        }
    }

    if (v.size()) {
        for (int i = 0; i < u.size(); ++i) {
            l = 0, r = (int)v.size() - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (u[i] * 2 + v[mid] <= t) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (u[i] * 2 + v[r] <= t) {
                ans = max(ans, i + r + 2);
            }
        }
    }

    swap(u, v);
    if (v.size()) {
        for (int i = 0; i < u.size(); ++i) {
            l = 0, r = (int)v.size() - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (u[i] * 2 + v[mid] <= t) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (u[i] * 2 + v[r] <= t) {
                ans = max(ans, i + r + 2);
            }
        }
    }
    cout << ans << endl;

    return 0;
}