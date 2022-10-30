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
#define __ cout << __LINE__ << endl
#else
#define db(x)
#define __
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, k;
int a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        if (k == 1 || k == n) {
            cout << "YES" << endl;
            continue;
        }
        vector<pair<LL, LL>> u, v;
        for (int i = k + 1; i <= n; ++i) {
            LL x = a[i], y = min(x, 0LL);
            int j = i;
            while (j + 1 <= n && x < 0) {
                ++j;
                x += a[j];
                y = min(x, y);
            }
            y = -y;
            u.push_back({x, y});
            i = j;
        }
        for (int i = k - 1; i > 0; --i) {
            LL x = a[i], y = min(x, 0LL);
            int j = i;
            while (j - 1 > 0 && x < 0) {
                --j;
                x += a[j];
                y = min(x, y);
            }
            y = -y;  // positive cost
            v.push_back({x, y});
            i = j;
        }
        LL cnt = a[k];
        int p0 = 0, p1 = 0;
        while (p0 < u.size() && p1 < v.size()) {
            if (u[p0].first >= 0 && cnt >= u[p0].second) {
                cnt += u[p0].first;
                db(cnt);
                ++p0;
                continue;
            }
            if (v[p1].first >= 0 && cnt >= v[p1].second) {
                cnt += v[p1].first;
                db(cnt);
                ++p1;
                continue;
            }
            break;
        }
        if (p0 == u.size() || p1 == v.size()) {
            cout << "YES" << endl;
            continue;
        }
        if (p0 + 1 == u.size() && cnt >= u.back().second) {
            cout << "YES" << endl;
            continue;
        }
        if (p1 + 1 == v.size() && cnt >= v.back().second) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}