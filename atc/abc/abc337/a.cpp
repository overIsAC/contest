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

int main() {
    int T;
    cin >> T;
    int u = 0, v = 0;
    while (T--) {
        int a, b;
        cin >> a >> b;
        u += a;
        v += b;
    }
    if (u > v) {
        cout << "Takahashi";
    } else if (u == v) {
        cout << "Draw";
    } else {
        cout << "Aoki";
    }
    return 0;
}