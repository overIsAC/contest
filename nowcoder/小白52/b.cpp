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
    int T, n;

    auto solve = [](int &n) {
        for (int i = 1, j = 1; i <= 8; ++i, j *= 10) {
            int p = n / j % 10;
            if (p >= 5) {
                n = n / j * j;
                while (p) {
                    n += j;
                    p = n / j % 10;
                }
                return true;
            }
        }
        return false;
    };

    cin >> T;

    while (T--) {
        cin >> n;
        while (solve(n))
            ;
        cout << n << endl;
    }
    return 0;
}