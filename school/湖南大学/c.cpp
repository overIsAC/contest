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
const int N = 3 + 2e5;

int main() {
    int n;
    cin >> n;
    --n;
    for (int i = n - !(n % 2); i >= 1; i -= 2) {
        cout << i << ' ';
    }
    for (int i = n - (n % 2); i >= 1; i -= 2) {
        cout << i << ' ';
    }
    cout << n + 1;
    return 0;
}