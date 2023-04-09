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

int n, a[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        LL ans = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 2; i <= n; ++i) {
            q.push(a[i]);
        }
        while (q.size()) {
            int x = q.top();
            q.pop();
            if (a[1] > x) {
                continue;
            }
            int v = (a[1] + x + 1) / 2;
            a[1] = v;
        }
        cout << a[1] << endl;
    }
    return 0;
}