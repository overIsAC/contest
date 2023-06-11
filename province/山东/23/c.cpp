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

void dfs(int x) {
    if (key[x]) {
        mp[x][d[x]] += 1;
    }
    vector<int> seq;
    for (auto &y : edge[x]) {
        d[y] = d[x] + 1;
        dfs(y);
        seq.push_back(y);
    }
    sort(seq.begin(), seq.end(), [&](int &x, int &y) {
        auto it1 = mp[x].begin(), it2 = mp[y].begin();
        int p = 1e9;
        while (it1 != mp[x].end() && it2 != mp[y].end()) {
            if (*it1 != *it2) {
                if (it1->first != it2->first) {
                    return it1->first < it2->first;
                } else {
                    if 9
                }
            }
            ++it1;
            ++it2;
        }
        if (mp[x].size() == mp[y].size()) {
            return x < y;
        }
        return mp[x].size() < mp[y].size();
    });
    for (int i = 0; i < seq.size(); ++i) {
        int y = seq[i];
        ans[y] = i + 'a';
        if (mp[x].size() < mp[y].size()) {
            swap(mp[x], mp[y]);
        }
        for (auto &[u, v] : mp[y]) {
            mp[x][u] += v;
        }
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
        cout << ans + 1 << endl;
    }

    return 0;
}
/*
6 3
0 1 2 2 1 5
3 4 6

6 4
0 1 2 2 1  5
3 4 6 5

*/