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

int pre[N];

int f(int n) {
    int ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    for (int i = 1; i <= 2e5; ++i) {
        pre[i] = pre[i - 1] + f(i);
    }

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << pre[n] << endl;
    }
    return 0;
}