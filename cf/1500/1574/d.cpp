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
const int N = 3 + 2e5;

int n, m[11];
int a[11][N];
int t;

struct Node {
    LL v;
    int p;
    vector<int> ve;
    bool operator<(const Node &other) const {
        return v < other.v;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m[i];
        for (int j = 1; j <= m[i]; ++j) {
            cin >> a[i][j];
        }
    }
    cin >> t;
    vector<vector<int>> ve;
    for (int i = 1; i <= m[1]; ++i) {
        ve.push_back({i});
    }
    reverse(ve.begin(), ve.end());
    for (int i = 2; i <= n; ++i) {
        priority_queue<Node> q;
        for (auto &j : ve) {
            LL sum = 0;
            for (int k = 1; k < i; ++k) {
                sum += a[k][j[k - 1]];
            }
            q.push({sum + a[i][m[i]], m[i], j});
        }
        ve.clear();
        while (q.size() && ve.size() <= t + 1) {
            auto x = q.top();
            q.pop();
            auto vv = x.ve;
            vv.push_back(x.p);
            ve.push_back(vv);

            x.v -= a[i][x.p];
            --x.p;

            if (x.p >= 1) {
                x.v += a[i][x.p];
                q.push(x);
            }
        }
    }
    set<vector<int>> st;
    while (t--) {
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        st.insert(a);
    }
    db(ve.size());
    for (auto &i : ve) {
        if (st.count(i)) {
            continue;
        }
        for (auto &j : i) {
            cout << j << ' ';
        }
        return 0;
    }
    return 0;
}