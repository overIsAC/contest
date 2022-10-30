#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
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
char s[N];
LL dp[N];
int num[N];

LL calc(int l, int r) {
    LL ans = 0;
    for (int i = l; i <= r; ++i) {
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}

int main() {
    cin >> s + 1;
    n = strlen(s + 1);
    num[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[j - 1] + (LL)calc(j, i) * num[j - 1];
            num[i] += num[j - 1];
        }
    }
    cout << dp[n] << endl;
    return 0;
}