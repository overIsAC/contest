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

int n, s, k;

int main() {
    cin >> n >> s >> k;
    int sum = 0;
    while (n--) {
        int p, q;
        cin >> p >> q;
        sum += p * q;
    }
    if (sum < s) {
        sum += k;
    }
    cout << sum << endl;
    return 0;
}