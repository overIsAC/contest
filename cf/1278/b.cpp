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
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int c = b - a;
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = l + r >> 1;
            if ((LL)mid * (mid + 1) / 2 >= c)
                r = mid;
            else
                l = mid + 1;
        }
        while (r * (r + 1) / 2 + c & 1) ++r;
        cout << r << endl;
    }
    return 0;
}