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
const int N = 3 + 1e6;

vector<int> ve[10];

int f(int i) {
    int mx = 0, mn = 9;
    do {
        mx = max(mx, i % 10);
        mn = min(mn, i % 10);
        i /= 10;
    } while (i);
    return mx - mn;
}

int main() {
    for (int i = 1; i < N; ++i) {
        ve[f(i)].push_back(i);
    }
    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        int ans = l;
        for (int i = 0; i <= 9; ++i) {
            auto p = lower_bound(ve[i].begin(), ve[i].end(), l);
            if (p == ve[i].end() || *p > r) {
                continue;
            }
            ans = *p;
        }
        cout << ans << endl;
    }
    return 0;
}