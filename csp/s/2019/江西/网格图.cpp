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
const int N = 3 + 3e5;

int n, m, a[N], b[N];

struct Node {
    int p, type;
    int get() const {
        if (type == 0) {
            return a[p];
        } else {
            return b[p];
        }
    }
    bool operator<(const Node &other) const {
        return get() < other.get();
    }
};

vector<Node> ve;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i < n; ++i) {
        ve.push_back({0, i});
    }
    for (int i = 1; i < m; ++i) {
        ve.push_back({1, i});
    }
    sort(ve.begin(), ve.end());
    LL ans = 0;
    int minX = 1e9, maxX = 0;
    int minY = 1e9, maxY = 0;
    for (auto &i : ve) {
        if (i.type == 0) {
            if (maxX) {
            } else {
                ans += (LL)(m - 1) * i.get();
            }
        } else {
        }
    }
    cout << ans << endl;
    return 0;
}