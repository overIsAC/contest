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
const int N = 3 + 1e5;

pair<LL, LL> get(int a, int b, int n) {
    if (n == 1) {
        return {1, a};
    }
    LL d = (LL)(n - 1) * (a - b);
    return {d + b + 1, d + a};
}

LL calc(int a, int b, LL h) {
    if (h <= a) {
        return 1;
    }
    return 1 + (h - a + (a - b - 1)) / (a - b);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        LL L = 1, R = 4e18;
        map<pair<LL, LL>, LL> mp;
        int n, a, b, q, op;
        cin >> q;
        vector<LL> ans(q);
        for (auto &i : ans) {
            cin >> op;
            if (op == 1) {
                cin >> a >> b >> n;
                if (mp.count({a, b})) {
                    if (mp[{a, b}] != n) {
                        i = 0;
                    } else {
                        i = 1;
                    }
                    continue;
                }
                auto v = get(a, b, n);
                if (max(v.first, L) > min(v.second, R)) {
                } else {
                    i = 1;
                    mp[{a, b}] = n;
                    L = max(v.first, L);
                    R = min(v.second, R);
                }
            } else {
                cin >> a >> b;
                auto u = calc(a, b, L);
                auto v = calc(a, b, R);
                // cout << "uv" << ' ' << u << ' ' << v << endl;
                if (u != v) {
                    i = -1;
                    continue;
                }
                if (mp.count({a, b})) {
                    i = mp[{a, b}];
                    continue;
                }
                i = v;
            }
            // cout << L << " " << R << endl;
        }
        for (auto &i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}