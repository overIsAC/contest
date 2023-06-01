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
        set<PII> ans;

        map<int, multiset<int>> mpa;
        map<int, multiset<int>> mpb;

        auto erase = [&](int u, int v) -> bool {
            if (!mpa.count(u) || mpa[u].find(v) == mpa[u].end()) {
                return false;
            }
            if (!mpb.count(v) || mpb[v].find(u) == mpb[v].end()) {
                return false;
            }
            mpa[u].erase(mpa[u].find(v));
            if (mpa[u].empty()) {
                mpa.erase(u);
            }
            mpb[v].erase(mpb[v].find(u));
            if (mpb[v].empty()) {
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
                    if (erase(x, y)) {
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
        int t = *mpa[maxa].rbegin();
        if (t >= maxb && t <= sum / maxa) {
            erase(maxa, t);
            if (check(maxa, sum / maxa - t)) {
                ans.insert({maxa, sum / maxa});
            }
            mpa.clear();
            mpb.clear();
            for (int i = 1; i <= n; ++i) {
                mpa[a[i]].insert(b[i]);
                mpb[b[i]].insert(a[i]);
            }
        }
        t = *mpb[maxb].rbegin();
        if (t >= maxa && t <= sum / maxb) {
            erase(t, maxb);
            if (check(sum / maxb - t, maxb)) {
                ans.insert({sum / maxb, maxb});
            }
        }
        cout << ans.size() << endl;
        for (auto& i : ans) {
            cout << i.first << ' ' << i.second << endl;
        }
    }
    return 0;
}