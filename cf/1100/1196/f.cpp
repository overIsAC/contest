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

struct Node {
    int u, v;
    LL w;
    bool operator<(const Node &other) const {
        if (w != other.w) {
            return w < other.w;
        }
        if (u != other.u) {
            return u < other.u;
        }
        return v < other.v;
    }
};

int n, m, k;
vector<PII> edge[N];
LL maxW = 1e18;
set<Node> ans;
map<PII, LL> minA;


// 乱搞... 

void bfs(int s) {
    priority_queue<pair<LL, int>> q;
    map<int, LL> d;
    set<int> vis;
    q.push({0, s});
    d[s] = 0;
    vector<int> zz;

    auto push = [&](int u, int v, LL w) {
        if (w == 0) {
            return;
        }
        if (u > v) {
            swap(u, v);
        }
        if (minA.count({u, v})) {
            // 保留 (u,v) 最短的路径；如果不处理，应该会出错
            if (minA[{u, v}] > w) {
                ans.erase({u, v, minA[{u, v}]});
                minA[{u, v}] = w;
                ans.insert({u, v, w});
            }
        } else {
            minA[{u, v}] = w;
            ans.insert({u, v, w});
        }
        if (ans.size() > k) {
            ans.erase(prev(ans.end()));
            maxW = min(maxW, ans.rbegin()->w);
        }
    };

    for (int i = 1; i <= k + 1 && q.size(); ++i) {
        int x = q.top().second;
        q.pop();
        if (vis.count(x)) {
            continue;
        }
        if (d[x] > maxW) {
            break;
        }
        zz.push_back(x);
        vis.insert(x);
        for (auto [y, w] : edge[x]) {
            if (!d.count(y) || d[y] > d[x] + w) {
                if ((d[y] = d[x] + w) >= maxW) {
                    continue;
                }
                q.push({-d[y], y});
            }
        }
    }

    for (int i = 0; i < zz.size(); ++i) {
        for (int j = i + 1; j < zz.size(); ++j) {
            if (d[zz[i]] + d[zz[j]] >= maxW) {
                break;
            }
            push(zz[i], zz[j], d[zz[i]] + d[zz[j]]);
        }
    }

    edge[s].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    vector<int> seq;
    for (int i = 1; i <= n; ++i) {
        seq.push_back(i);
    }
    sort(seq.begin(), seq.end(), [](int u, int v) {
        return edge[u].size() > edge[v].size();
    });
    for (auto i : seq) {
        bfs(i);
    }

    // cout << endl;
    // for (auto [u, v, w] : ans) {
    //     cout << u << ' ' << v << ' ' << w << endl;
    // }
    cout << ans.rbegin()->w << endl;
    return 0;
}