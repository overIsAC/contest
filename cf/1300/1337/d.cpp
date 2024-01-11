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

void solve() {
    int na, nb, nc;
    cin >> na >> nb >> nc;
    vector<int> a(na), b(nb), c(nc);
    for (auto& i : a) {
        cin >> i;
    }
    for (auto& i : b) {
        cin >> i;
    }
    for (auto& i : c) {
        cin >> i;
    }

    set<int> sa(a.begin(), a.end());
    set<int> sb(b.begin(), b.end());
    set<int> sc(c.begin(), c.end());

    LL ans = 9e18;

    auto update = [&](LL a, LL b, LL c) {
        ans = min(ans, (a - b) * (a - b) + (b - c) * (b - c) + (a - c) * (a - c));
    };

    for (auto& i : sa) {
        auto pb1 = sb.lower_bound(i);
        auto pb2 = pb1;
        if (pb2 != sb.begin()) {
            --pb2;
        }
        auto pc1 = sc.lower_bound(i);
        auto pc2 = pc1;
        if (pc2 != sb.begin()) {
            --pc2;
        }

        vector<decltype(pb1)> vb = {pb1, pb2};
        vector<decltype(pc1)> vc = {pc1, pc2};
        vector<decltype(pc1)> ed = {sb.end(), sc.end()};

        for (auto& j : vb) {
            for (auto& k : vc) {
                if (j != ed[0] && k != ed[1]) {
                    update(i, *j, *k);
                }
            }
        }
    }
    for (auto& i : sb) {
        auto pa1 = sa.lower_bound(i);
        auto pa2 = pa1;
        if (pa2 != sa.begin()) {
            --pa2;
        }
        auto pc1 = sc.lower_bound(i);
        auto pc2 = pc1;
        if (pc2 != sb.begin()) {
            --pc2;
        }

        vector<decltype(pa1)> vb = {pa1, pa2};
        vector<decltype(pc1)> vc = {pc1, pc2};
        vector<decltype(pc1)> ed = {sa.end(), sc.end()};

        for (auto& j : vb) {
            for (auto& k : vc) {
                if (j != ed[0] && k != ed[1]) {
                    update(i, *j, *k);
                }
            }
        }
    }
    for (auto& i : sc) {
        auto pb1 = sb.lower_bound(i);
        auto pb2 = pb1;
        if (pb2 != sb.begin()) {
            --pb2;
        }
        auto pa1 = sa.lower_bound(i);
        auto pa2 = pa1;
        if (pa2 != sb.begin()) {
            --pa2;
        }

        vector<decltype(pb1)> vb = {pb1, pb2};
        vector<decltype(pa1)> vc = {pa1, pa2};
        vector<decltype(pb1)> ed = {sb.end(), sa.end()};

        for (auto& j : vb) {
            for (auto& k : vc) {
                if (j != ed[0] && k != ed[1]) {
                    update(i, *j, *k);
                }
            }
        }
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