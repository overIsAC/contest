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
const int N = 3 + 4e5;

vector<int> edge[N];
int n;
int ans[N];

void dfs(int x) {
    for (int& y : edge[x]) {
        ans[y] = ans[x] + 1;
        dfs(y);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        edge[a].push_back(i * 2);
        edge[a].push_back(i * 2 + 1);
    }
    dfs(1);
    for (int i = 1; i <= 2 * n + 1; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}