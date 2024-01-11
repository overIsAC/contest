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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    int mul = 1;
    for (auto& i : a) {
        mul *= i;
        if (mul > 2023) {
            cout << "NO" << endl;
            return;
        }
    }
    if (2023 % mul) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    if (mul < 2023) {
        cout << 2023 / mul << ' ';
        --k;
    }
    while (k--) {
        cout << 1 << ' ';
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}