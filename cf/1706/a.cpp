#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 333;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, a[N];
        char s[N] = {0};
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; ++i) {
            s[i] = 'B';
        }
        for (int i = 1; i <= n; ++i) {
            int p1 = a[i], p2 = m + 1 - a[i];
            if (p1 > p2) swap(p1, p2);
            if (s[p1] == 'B')
                s[p1] = 'A';
            else
                s[p2] = 'A';
        }
        cout << s + 1 << endl;
    }
    return 0;
}