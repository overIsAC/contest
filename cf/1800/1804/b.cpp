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
const int N = 3 + 2e5;

int n, k, d, w, t[N];

void solve() {
    int cnt = 0, last = 0;
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i) {
        while (q.size() && q.top() + w < t[i]) {
            if (last + d + 1 <= q.top()) {
                cnt = 0;
            }
            if (cnt == 0) {
                last = q.top() + w;
                cnt = k;
                ++ans;
            }
            --cnt;
            q.pop();
        }
        q.push(t[i]);
        while (q.size() && cnt) {
            if (last + d + 1 <= q.top()) {
                cnt = 0;
            } else {
                --cnt;
                q.pop();
            }
        }
    }
    while (q.size()) {
        if (last + d + 1 <= q.top()) {
            cnt = 0;
        }
        if (cnt == 0) {
            last = q.top() + w;
            cnt = k;
            ++ans;
        }
        --cnt;
        q.pop();
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k >> d >> w;
        for (int i = 1; i <= n; ++i) {
            cin >> t[i];
        }
        solve();
    }
    return 0;
}