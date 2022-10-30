#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;
vector<int> edge[N];
int c[N];
int ans;

void dfs(int x, int col) {
    if (col != c[x]) {
        ++ans;
        col = c[x];
    }
    for (int &y : edge[x]) {
        dfs(y, col);
    }
}

int main() {
    cin >> n;
    for (int i = 2, u; i <= n; ++i) {
        cin >> u;
        edge[u].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}