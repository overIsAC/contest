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

vector<int> ans;
vector<int> sq;

void solve(int n) {
    auto p = lower_bound(sq.begin(), sq.end(), n);
    if (n == *p) {
        for (int i = 0; i <= n; ++i) {
            ans.push_back(i);
        }
        return;
    }
    int m = *p - n;
    for (int i = m; i <= n; ++i) {
        ans.push_back(i);
    }
    solve(m - 1);
}

int main() {
    for (int i = 0; i * i <= 2e5; ++i) {
        sq.push_back(i * i);
    }
    int T;
    cin >> T;
    while (T--) {
        ans.clear();
        int n;
        cin >> n;
        solve(n-1);
        reverse(ans.begin(),ans.end());
        for (auto &i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}