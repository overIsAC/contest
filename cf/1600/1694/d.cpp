#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, L[N], R[N];
vector<int> edge[N];
int ans;
multiset<int> s[N];
LL sum[N];
LL now[N];

void dfs(int x) {
    for (int &y : edge[x]) {
        dfs(y);
        if (s[x].size() < s[y].size()) swap(s[x], s[y]);
        s[x].insert(s[y].begin(), s[y].end());
        s[y].clear();
        sum[x] += sum[y];
    }
    if (sum[x] < L[x]) {
        s[x].insert(R[x] - sum[x]);
        sum[x] = R[x];
        ++ans;
    } else {
        bool flag = false;
        while (s[x].size() && sum[x] > R[x]) {
            flag = true;
            sum[x] -= *(--s[x].end());
            s[x].erase(--s[x].end());
        }
        if (flag) {
            s[x].insert(R[x] - sum[x]);
            sum[x] = R[x];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            s[i].clear();
            edge[i].clear();
            now[i] = 0;
            sum[i] = 0;
        }
        for (int i = 2, u, v; i <= n; ++i) {
            cin >> u;
            v = i;
            edge[u].push_back(v);
        }
        for (int i = 1; i <= n; ++i) {
            cin >> L[i] >> R[i];
        }
        ans = 0;
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}