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

int n, m;
LL ans[N];
priority_queue<int, vector<int>, greater<int>> q;
priority_queue<PII, vector<PII>, greater<PII>> q2;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    while (m--) {
        int t, w, s;
        cin >> t >> w >> s;
        while (q2.size() && q2.top().first <= t) {
            q.push(q2.top().second);
            q2.pop();
        }
        if (q.size()) {
            int x = q.top();
            q.pop();
            ans[x] += w;
            q2.push({t + s, x});
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}