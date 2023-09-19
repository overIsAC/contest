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
const int M = 3 + 2e6;

int n, a[N];
int pre[M];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[a[i]] = 1;
    }
    for (int i = 1; i < M; ++i) {
        pre[i] += pre[i - 1];
    }
    int ans = 0;
    for (int i = M - 1; i >= 1; --i) {
        if (ans >= i) {
            break;
        }
        if (pre[i] - pre[i - 1] == 0) {
            continue;
        }
        for (int j = i + i; j < M; j += i) {
            while (pre[j - 1] - pre[j - i + ans] > 0) {
                ++ans;
            }
        }
    }
    cout << ans << endl;

    return 0;
}