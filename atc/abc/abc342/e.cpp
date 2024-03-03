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

struct Edge {
    int l, d, k, c, a, b;
};

int n, m;
vector<Edge> edge[N];
LL dd[N];
int vis[N];

int main() {
    cin >> n >> m;
    while (m--) {
        int l, d, k, c, a, b;
        cin >> l >> d >> k >> c >> a >> b;
        edge[b].push_back({l, d, k, c, a, b});
    }
    queue<int> q;
    q.push(n);
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (vis[x]) {
            continue;
        }
        for (auto [l, d, k, c, a, b] : edge[x]) {
            if (dd[b] < l + c) {
                continue;
            }
        }
    }

    return 0;
}