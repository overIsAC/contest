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

int n;
int f[N];

int main() {
    cin >> n;
    for (int i = 2; i <= n + 1; ++i) {
        if (f[i]) {
            continue;
        }
        for (int j = i * i; j <= n + 1; j += i) {
            f[j] = 2;
        }
    }
    if (n >= 3) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
    for (int i = 2; i <= n + 1; ++i) {
        if (!f[i]) {
            f[i] = 1;
        }
        cout << f[i] << ' ';
    }
    return 0;
}