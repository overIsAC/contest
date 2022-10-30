#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3e5;

int n, m;
vector<int> edge[N];
int col[N];
bool vis[N];

int main() {
    int T, u, v;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            col[i] = 0;
            edge[i].clear();
            vis[i] = false;
        }
        while (m--) {
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        queue<int> q;
        col[1] = 1;
        q.push(1);
        int cnt = 0;
        int total = 0;
        while (q.size()) {
            int x = q.front();
            q.pop();
            if (vis[x]) continue;
            vis[x] = true;
            int c = 1;
            ++cnt;
            for (int &y : edge[x]) {
                if (col[y] == 1) {
                    c = 2;
                } else if (!vis[y]) {
                    q.push(y);
                }
            }
            col[x] = c;
            if (c == 1) {
                ++total;
            }
        }
        if (cnt == n) {
            cout << "YES" << endl;
            cout << total << endl;
            for (int i = 1; i <= n; ++i) {
                if (col[i] == 1) {
                    cout << i << ' ';
                }
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}