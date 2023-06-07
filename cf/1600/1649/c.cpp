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
const int N = 3 + 1e5;

int n, m;
map<int, vector<PII>> mp;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int a;
            cin >> a;
            mp[a].push_back({i, j});
        }
    }
    LL ans = 0;
    for (auto& [x, y] : mp) {
        sort(y.begin(), y.end());
        LL sum = 0, cnt = 0;
        for (auto& i : y) {
            ans += cnt * i.first - sum;
            sum += i.first;
            ++cnt;
        }
        sort(y.begin(), y.end(), [](PII& a, PII& b) {
            return a.second < b.second;
        });
        sum = 0;
        cnt = 0;
        for (auto& i : y) {
            ans += cnt * i.second - sum;
            sum += i.second;
            ++cnt;
        }
    }
    cout << ans << endl;
    return 0;
}