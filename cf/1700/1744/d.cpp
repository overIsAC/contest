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

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a[N];

int main() {
    int T;
    cin >> T;

    auto calc = [&](int v) {
        int ans = 0;
        while (v % 2 == 0) {
            ans += 1;
            v /= 2;
        }
        return ans;
    };

    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int sum = 0;
        priority_queue<int> q;
        for (int i = 1; i <= n; ++i) {
            sum += calc(a[i]);
            int v = calc(i);
            if (v)
                q.push(v);
        }
        int ans = 0;
        while (q.size() and n > sum) {
            int x = q.top();
            q.pop();
            sum += x;
            ans += 1;
        }
        db(sum);
        db(ans);
        if (n > sum)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}