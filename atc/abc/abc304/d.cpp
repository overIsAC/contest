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

int n, m, t;

int main() {
    cin >> n >> m >> t;
    vector<int> p(t), q(t);
    for (int i = 0; i < t; ++i) {
        cin >> p[i] >> q[i];
    }
    set<int> st1, st2;
    st1.insert(0);
    st2.insert(0);
    int A, B;
    cin >> A;
    for (int i = 1; i <= A; ++i) {
        int a;
        cin >> a;
        st1.insert(a);
    }
    cin >> B;
    for (int i = 1; i <= B; ++i) {
        int b;
        cin >> b;
        st2.insert(b);
    }
    map<PII, int> mp;
    for (int i = 0; i < t; ++i) {
        auto it1 = --st1.lower_bound(p[i]);
        auto it2 = --st2.lower_bound(q[i]);
        mp[{*it1, *it2}] += 1;
    }
    int ans1 = 1e9, ans2 = 0;
    for (auto [x, y] : mp) {
        ans1 = min(ans1, y);
        ans2 = max(ans2, y);
    }
    if ((LL)(A + 1) * (B + 1) > mp.size()) {
        ans1 = 0;
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}