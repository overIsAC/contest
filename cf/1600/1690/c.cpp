#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n;
int a[N], b[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        int now = 0;
        for (int i = 1; i <= n; ++i) {
            now = max(now, a[i]);
            cout << b[i] - now << ' ';
            now = b[i];
        }
        cout << endl;
    }
    return 0;
}