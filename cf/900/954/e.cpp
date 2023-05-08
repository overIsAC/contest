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

int n, T;
int a[N], t[N];
vector<PII> u, v;
LL w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> T;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        t[i] -= T;
        if (t[i] == 0) {
            w += a[i];
        } else {
            if (t[i] < 0) {
                u.push_back({-t[i], a[i]});
            } else {
                v.push_back({t[i], a[i]});
            }
        }
    }
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());

    LL x = 0, y = 0;
    for (auto &i : u) {
        x += (LL)i.first * i.second;
    }
    for (auto &i : v) {
        y += (LL)i.first * i.second;
    }
    if (x < y) {
        swap(u, v);
        swap(x, y);
    }
    // cout << x << ' ' << y << endl;
    long double l = 0, r = 1e12;

    auto calc = [&](long double c) -> long double {
        long double cnt = 0;
        for (auto &i : u) {
            long double t = c;
            if (t > i.second) {
                t = i.second;
            }
            cnt += t * i.first;
            c -= t;
        }
        return cnt;
    };
    while (r - l > 1e-8) {
        long double mid = (l + r) / 2;
        if (calc(mid) < y) {
            l = mid;
        } else {
            r = mid;
        }
    }
    // cout << x << ' ' << y << endl;
    long double ans = r + w;
    // cout << ans << ' ' << r << ' ' << w << ' ' << v[0].first << ' ' << v[0].second << endl;
    for (auto &i : v) {
        ans += i.second;
    }
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}