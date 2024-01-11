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

int n, k[N], a, b;
int d[N];

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
    }
    memset(d, 0x3f, sizeof(d));
    d[a] = 0;

    queue<int> q;
    q.push(a);
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x - k[x] >= 1 && d[x - k[x]] > d[x] + 1) {
            d[x - k[x]] = d[x] + 1;
            q.push(x - k[x]);
        }
        if (x + k[x] >= 1 && d[x + k[x]] > d[x] + 1) {
            d[x + k[x]] = d[x] + 1;
            q.push(x + k[x]);
        }
    }
    int ans = d[b];
    if (ans > 1e9) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}