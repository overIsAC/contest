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
        int x, a[4] = {0};
        cin >> x;
        int cnt = 1;
        for (int i = 1; i <= 3; ++i) {
            cin >> a[i];
        }
        while (a[x]) {
            ++cnt;
            int y = a[x];
            a[x] = 0;
            x = y;
        }
        if (cnt == 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}