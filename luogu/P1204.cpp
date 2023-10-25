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
const int N = 3 + 1e6;

int pre[N], n;

int main() {
    cin >> n;
    int c = 0;
    while (n--) {
        int l, r;
        cin >> l >> r;
        ++pre[l];
        --pre[r];
        c = max(c, r);
    }
    for (int i = 1; i <= c; ++i) {
        pre[i] += pre[i - 1];
        // cout << i << ' ' << pre[i] << endl;
    }

    int a = 0, b = 0;
    for (int i = 0; i <= c; ++i) {
        int j = i;
        while (j + 1 <= c && (!pre[j + 1]) == (!pre[j])) {
            ++j;
        }
        if (pre[i]) {
            if (a < j - i + 1) {
                a = j - i + 1;
            }
        } else if (a && !pre[i] && (j < c)) {
            if (b < j - i + 1) {
                b = j - i + 1;
            }
        }
        i = j;
    }
    cout << a << ' ' << b << endl;

    return 0;
}