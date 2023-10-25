#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using ULL = unsigned long long;
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

ULL n, k;

void dfs(__int128_t n, __int128_t k) {
    if (n == 0) {
        return;
    }
    if (((__int128_t)1 << (n - 1)) <= k) {
        cout << 1;
        dfs(n - 1, ((__int128_t)1 << n) - 1 - k);
    } else {
        cout << 0;
        dfs(n - 1, k);
    }
}

int main() {
    cin >> n >> k;
    dfs(n, k);
    return 0;
}