#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 3 + 2e5;

int n, m;

vector<int> edge[N];
map<int, int> mp[N];
int key[N];
char ans[N];
int d[N];
int rk[N];
vector<int> seq[N];

void dfs(int x) {
    seq[d[x]].push_back(x);
    for (auto &y : edge[x]) {
        d[y] = d[x] + 1;
        dfs(y);
    }
}

int cmp(int x, int y) {
    if (key[x] != key[y]) {
        return key[x] > key[y] ? -1 : 1;
    }
    int flag = 0;
    for (int i = 0; i < seq[x].size() && i < seq[y].size(); ++i) {
        int &u = seq[x][i], &v = seq[y][i];
        if (rk[u] != rk[v]) {
            flag = rk[u] < rk[v] ? -1 : 1;
            break;
        }
        int t = cmp(u, v);
        if (t) {
            flag = t;
            break;
        }
    }
    if (flag) {
        if (seq[x].size() == seq[x].size()) {
            return flag;
        }
        return seq[x].size() > seq[y].size() ? -1 : 1;
    }
    if (seq[x].size() == seq[x].size()) {
        return x < y ? -1 : 1;
    } else {
        return seq[x].size() > seq[y].size() ? 1 : -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--) {
        cin >> n >> m;
        for (int i = 0; i <= n; ++i) {
            edge[i].clear();
            mp[i].clear();
            seq[i].clear();
            key[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            int u, v;
            cin >> u;
            v = i;
            edge[u].push_back(i);
        }
        for (int i = 1; i <= m; ++i) {
            int x;
            cin >> x;
            key[x] = 1;
        }
        ans[n + 1] = 0;
        dfs(0);
        for (int i = n; i >= 1; --i) {
            auto &ve = seq[i];
            sort(ve.begin(), ve.end(), [&](int &a, int &b) {
                return cmp(a, b) < 0;
            });
            for (int j = 0; j < ve.size(); ++j) {
                rk[ve[j]] = j;
                ans[ve[j]] = j + 'a';
            }
        }
        cout << ans + 1 << endl;
    }

    return 0;
}