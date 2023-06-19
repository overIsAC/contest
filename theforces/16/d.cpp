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

const int LIMIT = (1 << 30) - 1;

int n, x;

void solve() {
    vector<int> ans;
    ans.push_back(x);
    while (ans.size() < n) {
        int j = 0, t = ans.back();
        while (j < 30 && (t >> j & 1)) {
            ++j;
        }
        if (j == 30) {
            cout << -1 << endl;
            return;
        }
        t |= 1 << j;
        while (--j >= 0) {
            t ^= 1 << j;
        }
        ans.push_back(t);
    }
    for (auto &i : ans) {
        cout << i << ' ';
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> x;
        solve();
    }
    return 0;
}