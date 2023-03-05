#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = INT_MAX;
    for (int i = 1; i < k; ++i) {
        if (n % i) continue;
        ans = min(ans, n / i * k + i);
    }
    cout << ans << endl;
    return 0;
}