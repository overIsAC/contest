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
    string a[3];
    for (auto& i : a) {
        cin >> i;
    }
    auto calc = [&](int x, int y) -> char {
        int sum = 'A' + 'B' + 'C' + '?';
        for (int i = 0; i < 3; ++i) {
            sum -= a[x][i];
        }
        return sum;
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (a[i][j] == '?') {
                cout << calc(i, j) << endl;
                return;
            }
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