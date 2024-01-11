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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;
const int M = 3 + 1e6;

int n, a[N];
int cnt[M], ans[M];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        ++cnt[a[i]];
    }
    for (int i = 1; i < M; ++i) {
        for (int j = i; j < M; j += i) {
            ans[j] += cnt[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[a[i]] - 1 << endl;
    }
    return 0;
}