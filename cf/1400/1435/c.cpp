#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n, a[N], b[N];
vector<PII> c;

int main() {
    for (int i = 1; i <= 6; ++i) {
        cin >> a[i];
    }
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (b[i] > a[j]) {
                c.push_back({b[i] - a[j], i});
            }
        }
    }
    sort(c.begin(), c.end());
    map<int, int> mp;
    int cnt = 0, ans = INT_MAX;
    for (int i = 0, j = 0; i < c.size(); ++i) {
        if (!mp[c[i].second]++) {
            ++cnt;
        }
        while (cnt == n) {
            ans = min(ans, c[i].first - c[j].first);
            if (!--mp[c[j].second]) {
                --cnt;
            }
            ++j;
        }
    }
    cout << ans << endl;
    return 0;
}