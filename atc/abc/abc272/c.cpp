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

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n;
vector<int> ve[2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        ve[a & 1].push_back(a);
    }
    sort(ve[0].begin(), ve[0].end(), greater<int>());
    sort(ve[1].begin(), ve[1].end(), greater<int>());
    int ans = -1;
    if (ve[0].size() >= 2) {
        ans = max(ve[0][0] + ve[0][1], ans);
    }
    if (ve[1].size() >= 2) {
        ans = max(ve[1][0] + ve[1][1], ans);
    }
    cout << ans << endl;
    return 0;
}