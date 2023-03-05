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
const int N = 3 + 2e6;

int f[N];

int main() {
    for (int i = 1; i <= 9; ++i) {
        for (int j = i; j < N; j *= 10) {
            ++f[j];
        }
    }
    for (int i = 1; i < N; ++i) {
        f[i] += f[i - 1];
    }
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        cout << f[x] << endl;
    }
    return 0;
}