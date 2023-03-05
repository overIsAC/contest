#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a;
LL b[2];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        b[i & 1] += (a + 1) / 2;
        b[i & 1 ^ 1] += a / 2;
    }
    cout << min(b[0], b[1]) << endl;
    return 0;
}