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
LL k;

void dfs(int n, LL k) {
    if (n < 1) {
        return;
    }
    if (k < (1LL << n - 1)) {
        cout << 0;
        dfs(n - 1, k);
    } else {
        cout << 1;
        dfs(n - 1, (1LL << n) - k - 1);
    }
}

int main() {
    cin >> n >> k;
    dfs(n, k);
    return 0;
}