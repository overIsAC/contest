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

void solve() {
    int n, p;
    cin >> n >> p;
    vector<PII> a(n);
    for (auto &[i, j] : a) {
        cin >> j;
    }
    for (auto &[i, j] : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    LL ans = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    PII c = {0, 0};
    for (auto &i : a) {
        if (c.second == 0) {
            if (q.size()) {
                c = q.top();
                q.pop();
            }
        }
        if (c.second == 0 || c.first > p) {
            ans += p;
        } else {
            --c.second;
            ans += c.first;
        }
        q.push(i);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}