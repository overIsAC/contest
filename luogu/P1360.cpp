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

int n, a[N], m;
map<vector<int>, int> mp;
vector<int> pre[N];

vector<int> operator+(vector<int> a, int b) {
    for (int i = 0; i < m; ++i) {
        a[i] += b >> i & 1;
    }
    return a;
}

vector<int> calc(vector<int> a) {
    for (int i = 0; i + 1 < m; ++i) {
        a[i] -= a[i + 1];
    }
    a.pop_back();
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    pre[0].resize(m);

    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    int ans = 0;
    mp[calc(pre[0])] = 0;
    for (int i = 1; i <= n; ++i) {
        auto t = calc(pre[i]);
        if (mp.count(t)) {
            ans = max(ans, i - mp[t]);
        } else {
            mp[t] = i;
        }
    }
    cout << ans << endl;
    return 0;
}