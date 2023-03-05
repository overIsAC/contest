#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];
int b[N], t;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        t = 0;
        for (int i = 1, j = n / 2 + 1; i <= n / 2; ++i, ++j) {
            b[++t] = a[i];
            if (j <= n) b[++t] = a[j];
        }
        if (n & 1) {
            b[++t] = a[n];
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (b[i + 1] < b[(i + 1) % n + 1] &&
                b[(i + 1) % n + 1] > b[(i + 2) % n + 1])
                ;
            else if (b[i + 1] > b[(i + 1) % n + 1] &&
                     b[(i + 1) % n + 1] < b[(i + 2) % n + 1])
                ;
            else {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
        if (ok) {
            for (int i = 1; i <= n; ++i) {
                cout << b[i] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}