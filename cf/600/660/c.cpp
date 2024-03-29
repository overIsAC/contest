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

int n, k, a[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = 1, r = 0;
    int cnt = 0;
    for (int i = 1, j = 1; i <= n; ++i) {
        if (a[i] == 0) {
            ++cnt;
        }
        while (cnt > k) {
            if (a[j] == 0) {
                --cnt;
            }
            ++j;
        }
        if (r - l + 1 < i - j + 1) {
            l = j;
            r = i;
        }
    }
    for (int i = l; i <= r; ++i) {
        a[i] = 1;
    }
    cout << r - l + 1 << endl;
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }
    return 0;
}