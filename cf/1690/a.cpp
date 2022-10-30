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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int p = (n - 3) / 3;
        int a = p, b = p, c = p;
        n -= 3 * p;
        b += 1;
        a += 2;
        n -= 3;
        if (n) {
            --n;
            ++a;
        }
        if (n) {
            --n;
            ++b;
        }
        cout << b << ' ' << a << ' ' << c << endl;
    }
    return 0;
}