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
const int M = 1024;

int n, m;
vector<int> a[N];
vector<int> b[N];
int c[N];
int cntb[M];
vector<PII> cntc[M];
LL cost[M];
vector<int> r[M];
int cc[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int t, x;
        cin >> t;
        while (t--) {
            cin >> x;
            b[i].push_back(x - 1);
        }
    }
    for (int i = 1; i <= m; ++i) {
        cin >> c[i];
        int t, x;
        cin >> t;
        while (t--) {
            cin >> x;
            a[i].push_back(x - 1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int st = 0;
        for (auto& j : b[i]) {
            st |= 1 << j;
        }
        cntb[st] += 1;
    }
    for (int i = 1; i <= m; ++i) {
        int st = 0;
        for (auto& j : a[i]) {
            st |= 1 << j;
        }
        cntc[st].push_back({c[i], i});
    }
    const int up = 1 << 9;
    for (int i = 0; i < up; ++i) {
        sort(cntc[i].begin(), cntc[i].end());
        while (cntc[i].size() > 2) {
            cntc[i].pop_back();
        }
    }

    memset(cost, 0x3f, sizeof(cost));
    for (int i = 0; i < up; ++i) {
        if (cntc[i].empty()) {
            continue;
        }
        if (cntc[i].size() >= 2) {
            cost[i] = min(cost[i], (LL)cntc[i][0].first + cntc[i][1].first);
            if (cost[i] == (LL)cntc[i][0].first + cntc[i][1].first) {
                r[i] = {cntc[i][0].second, cntc[i][1].second};
            }
        }
        for (int j = i + 1; j < up; ++j) {
            if (cntc[j].empty()) {
                continue;
            }
            cost[i | j] = min(cost[i | j], (LL)cntc[i][0].first + cntc[j][0].first);
            if (cost[i | j] == (LL)cntc[i][0].first + cntc[j][0].first) {
                r[i | j] = {cntc[i][0].second, cntc[j][0].second};
            }
        }
    }

    for (int i = 1; i < up; ++i) {
        for (int j = i; j > 0; j = (j - 1) & i) {
            cc[i] += cntb[j];
        }
    }

    int p = 1;
    for (int i = 1; i < up; ++i) {
        if (r[i].empty()) {
            continue;
        }
        if (cc[p] < cc[i] || (cc[p] == cc[i] && cost[p] > cost[i])) {
            // cout << "???" << r[p].size() << endl;
            p = i;
        }
    }
    if (r[p].empty()) {
        cout << 1 << ' ' << 2 << endl;
    } else {
        cout << r[p][0] << ' ' << r[p][1] << endl;
    }

    return 0;
}