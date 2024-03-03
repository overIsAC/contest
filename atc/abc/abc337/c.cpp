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

int n, cnt[N], a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int p = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            p = i;
        } else {
            cnt[a[i]] = i;
        }
    }
    cout << p << ' ';
    p = cnt[p];
    while (p) {
        cout << p << ' ';
        p = cnt[p];
    }

    return 0;
}