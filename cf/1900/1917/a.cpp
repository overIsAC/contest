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
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    for (auto& i : a) {
        if (i == 0) {
            cout << 0 << endl;
            return;
        }
    }
    int z = 0;
    for (auto& i : a) {
        if (i < 0) {
            ++z;
        }
    }
    if (z % 2) {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    cout << 1 << ' ' << 0 << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}