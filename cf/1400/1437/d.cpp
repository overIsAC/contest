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
const int N = 3 + 2e5;

int n, a[N], h[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            h[i] = 0;
        }
        queue<int> q;
        q.push(1);
        for (int i = 2; i <= n; ++i) {
            int x = q.front();
            q.pop();
            int j = i;
            q.push(a[i]);
            h[a[i]] = h[x] + 1;
            while (j + 1 <= n && a[j] < a[j + 1]) {
                ++j;
                h[a[j]] = h[x] + 1;
                q.push(a[j]);
            }
            i = j;
        }
        cout << *max_element(h + 1, h + n + 1) << endl;
    }
    return 0;
}