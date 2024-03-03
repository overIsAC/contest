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

void solve() {
    int n;
    cin >> n;
    int cnt[3] = {};
    while (n--) {
        int a;
        cin >> a;
        cnt[a % 3] += 1;
    }
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += i * cnt[i] % 3;
    }
    sum %= 3;
    if (sum == 0) {
        cout << 0 << endl;
        return;
    }
    if (sum == 2) {
        cout << 1 << endl;
    } else {
        if (cnt[1]) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}