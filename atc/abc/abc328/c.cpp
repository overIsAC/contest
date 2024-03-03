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
const int N = 3 + 3e5;

int n, q;
char s[N];
int pre[N];

int main() {
    cin >> n >> q;
    cin >> s + 1;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1];
        if (s[i] == s[i - 1]) {
            ++pre[i];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l] << endl;
    }
    return 0;
}