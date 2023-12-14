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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

struct Node {
    int left, right, value;
} a[N];

int n, ans;

void dfs(int x, int d) {
    if (!x) {
        return;
    }
    ans = max(ans, d);
    dfs(a[x].left, d + 1);
    dfs(a[x].right, d + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].left >> a[i].right;
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}