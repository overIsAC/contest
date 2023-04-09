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
const int N = 3 + 3e5;

int n, k;
int a[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> b;
    for (int i = 2; i <= n; ++i) {
        b.push_back(a[i] - a[i - 1]);
    }
    sort(b.begin(), b.end());
    int ans = a[n] - a[1];
    while (b.size() && --k) {
        ans -= b.back();
        b.pop_back();
    }
    cout << ans << endl;

    return 0;
}