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
        int n, a = 0, b = 0;
        cin >> n;
        int q = 0, w = 0;
        while (n--) {
            scanf("%d:%d", &q, &w);
            w += q * 60;
            if (w <= 8 * 60)
                ;
            else if (w <= 8 * 60 + 5)
                ++a;
            else
                ++b;
        }
        cout << a << ' ' << b << endl;
    }
    return 0;
}