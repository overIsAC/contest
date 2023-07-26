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

int n, a[N];
map<set<int>, LL> m, e, x;
char s[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> s + 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'M') {
            ++m[{a[i]}];
        }
        if (s[i] == 'E') {
            for (auto j : m) {
                auto p = j.first;
                p.insert(a[i]);
                e[p] += j.second;
            }
        }
        if (s[i] == 'X') {
            for (auto j : e) {
                auto p = j.first;
                p.insert(a[i]);
                x[p] += j.second;
            }
        }
    }
    LL ans = 0;
    for (auto [u, v] : x) {
        int mex = 0;
        while (u.count(mex)) {
            ++mex;
        }
        ans += mex * v;
    }
    cout << ans << endl;
    return 0;
}