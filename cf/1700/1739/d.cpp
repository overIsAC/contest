#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

vector<int> edge[N];
int n, k;

int dfs(int x, int &v, int r) {
    int md = 1;
    for (int &y : edge[x]) {
        int d = dfs(y, v, r);
        if (d == r) {
            --v;
        } else {
            md = max(md, d + 1);
        }
    }
    return md;
}

bool ok(int r) {
    int v = k;
    for (int &y : edge[1]) {
        dfs(y, v, r);
    }
    return v >= 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u;
            v = i + 1;
            edge[u].push_back(v);
        }
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (ok(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << r << endl;
    }
    return 0;
}
/*

9 1
1 2 3 4 2 6 1 4
*/