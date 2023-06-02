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

int n, a[N], b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
        }
        LL sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += (LL)a[i] * b[i];
        }
        int maxa = *max_element(a + 1, a + n + 1);
        int maxb = *max_element(b + 1, b + n + 1);
        set<pair<LL, LL>> ans;

        map<int, multiset<int>> mpa;
        map<int, multiset<int>> mpb;

        auto erase = [&](int u, int v) -> bool {
            if (!mpa.count(u) || !mpb.count(v)) {
                return 0;
            }
            auto& ma = mpa[u];
            auto& mb = mpb[v];
            if (ma.find(v) == ma.end() || mb.find(u) == mb.end()) {
                return 0;
            }
            ma.erase(ma.find(v));
            if (ma.empty()) {
                mpa.erase(u);
            }
            mb.erase(mb.find(u));
            if (mb.empty()) {
                mpb.erase(v);
            }
            return 1;
        };

        auto check = [&](LL lena, LL lenb) -> bool {
            while (mpa.size() && mpb.size()) {
                auto p = mpa.rbegin();
                int x = p->first, y = *(p->second.rbegin());
                if (x == lena || y == lenb) {
                    if (!erase(x, y)) {
                        return 0;
                    }
                    if (lena == x) {
                        lenb -= y;
                    } else {
                        lena -= x;
                    }
                    continue;
                }
                p = mpb.rbegin();
                y = p->first;
                x = *(p->second.rbegin());
                if (x == lena || y == lenb) {
                    if (!erase(x, y)) {
                        return 0;
                    }
                    if (lena == x) {
                        lenb -= y;
                    } else {
                        lena -= x;
                    }
                    continue;
                }
                return 0;
            }
            return 1;
        };

        for (int i = 1; i <= n; ++i) {
            mpa[a[i]].insert(b[i]);
            mpb[b[i]].insert(a[i]);
        }
        if (sum % maxa == 0 && check(maxa, sum / maxa)) {
            ans.insert({maxa, sum / maxa});
        }
        mpa.clear();
        mpb.clear();
        for (int i = 1; i <= n; ++i) {
            mpa[a[i]].insert(b[i]);
            mpb[b[i]].insert(a[i]);
        }

        if (sum % maxb == 0 && check(sum / maxb, maxb)) {
            ans.insert({sum / maxb, maxb});
        }
        cout << ans.size() << endl;
        for (auto& i : ans) {
            cout << i.first << ' ' << i.second << endl;
        }
    }
    return 0;
}