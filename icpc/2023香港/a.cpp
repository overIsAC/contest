#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
using LL = long long;

const int N = 3 + 2e5;

vector<int> edge[N];
int n;

int dfs(int x) {
    int cnt = 0, mx = 0;
    for (int &y : edge[x]) {
        int v = dfs(y);
        if (v > mx) {
            mx = v;
            cnt = 1;
        } else if (v == mx) {
            ++cnt;
        }
    }
    if (cnt == edge[x].size() && edge[x].size() != 1) {
        return mx + 1;
    } else {
        return mx;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            int u, v;
            cin >> u;
            v = i;
            edge[u].push_back(v);
        }
        cout << dfs(1) << endl;
    }

    return 0;
}
