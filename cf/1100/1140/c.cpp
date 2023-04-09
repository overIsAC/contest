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
const int N = 3 + 3e5;

PII a[N];
int n, k;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1, [&](const PII &a, const PII &b) {
        return a.second > b.second;
    });
    priority_queue<int, vector<int>, greater<int>> q;
    LL sum = 0;
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i].first;
        q.push(a[i].first);
        if (q.size() > k) {
            sum -= q.top();
            q.pop();
        }
        ans = max(ans, sum * a[i].second);
    }
    cout << ans << endl;
    return 0;
}