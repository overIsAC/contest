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
const int N = 3 + 1e5;

int n, a[N];
vector<int> q;

int cmp(int u, int v) {
    if (a[u] > a[v]) {
        return u;
    } else {
        return v;
    }
}

int cmp2(int u, int v) {
    if (a[u] < a[v]) {
        return u;
    } else {
        return v;
    }
}

int dfs(int d, int L, int R) {
    if (L == R) {
        return R;
    }
    int mid = (L + R) / 2;
    int ans1 = dfs(d + 1, L, mid);
    int ans2 = dfs(d + 1, mid + 1, R);
    if (d == 1) {
        return cmp2(ans1, ans2);
    } else {
        return cmp(ans1, ans2);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= (1 << n); ++i) {
        cin >> a[i];
    }
    cout << dfs(1, 1, 1 << n) << endl;
    return 0;
}