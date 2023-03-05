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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

struct Edge {
    int y, id;
};

vector<Edge> edge[N];
int n, m, k;
int d[N];
queue<int> q;
vector<string> ans;
string temp;
vector<vector<int>> ids;

void dfs(int x, int y, int c) {
    if (ans.size() >= k || c > 1) {
        return;
    }
    if (y == ids[x].size()) {
        if (c != 1) {
            return;
        }
        c = 0;
        ++x;
        y = 0;
    }
    if (x == ids.size()) {
        ans.push_back(temp);
        return;
    }
    temp[ids[x][y]] = '0';
    dfs(x, y + 1, c);
    temp[ids[x][y]] = '1';
    dfs(x, y + 1, c + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back({v, i});
        edge[v].push_back({u, i});
    }
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    q.push(1);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto& i : edge[x]) {
            int& y = i.y;
            if (d[y] > d[x] + 1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }

    temp = string(m, '1');

#if LEMON
    cout << "*******" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << i << ' ' << d[i] << endl;
    }
    cout << "********" << endl;
#endif

    for (int y = 1; y <= n; ++y) {
        vector<int> tmp;
        for (auto& i : edge[y]) {
            int &x = i.y, &id = i.id;
            if (d[y] == d[x]) {
                temp[id] = '0';
                continue;
            }
            if (d[y] < d[x]) {
                continue;
            }
            if (d[y] == d[x] + 1) {
                tmp.push_back(id);
            }
            if (d[y] > d[x] + 1) {
                temp[id] = '0';
            }
        }
        if (tmp.size())
            ids.push_back(tmp);
    }

    db(ids.size());

    if (ids.size())
        dfs(0, 0, 0);

    cout << ans.size() << endl;
    for (auto& i : ans) {
        cout << i << endl;
    }

    return 0;
}

/*

5 6 100
1 2
1 3
2 4
2 5
3 4
3 5
*/