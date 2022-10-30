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
        if (n % 2 == 0) {
            n /= 2;
            cout << 1 << ' ' << 1 << ' ' << (n ^ 1) << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}