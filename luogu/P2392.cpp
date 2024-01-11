#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int ans;

void dfs(vector<int>& a, int p, int cnt1, int cnt2) {
    if (p == a.size()) {
        ans = min(ans, max(cnt1, cnt2));
        return;
    }
    dfs(a, p + 1, cnt1 + a[p], cnt2);
    dfs(a, p + 1, cnt1, cnt2 + a[p]);
}

int solve(vector<int>& a) {
    vector<int> vis(a.size());
    ans = 1e9;
    dfs(a, 0, 0, 0);
    return ans;
}

int main() {
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    vector<int> a(n1), b(n2), c(n3), d(n4);
    for (auto& i : a) {
        cin >> i;
    }
    for (auto& i : b) {
        cin >> i;
    }
    for (auto& i : c) {
        cin >> i;
    }
    for (auto& i : d) {
        cin >> i;
    }
    cout << solve(a) + solve(b) + solve(c) + solve(d) << endl;
    return 0;
}