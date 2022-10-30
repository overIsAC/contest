#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;

        auto ok = [&](int l, int r) {
            cout << "? " << l << ' ' << r << endl;
            int cnt = 0;
            for (int i = r - l + 1, v; i; --i) {
                cin >> v;
                if (l <= v && v <= r) ++cnt;
            }
            return cnt % 2 == 1;
        };

        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (ok(l, mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << "! " << r << endl;
    }
    return 0;
}