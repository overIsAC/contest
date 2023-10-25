#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3e5;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int p = 1;
    string ans;
    int dir = 1;
    while (true) {
        if (!a[p] && !a[p - 1]) {
            break;
        }
        if (dir) {
            if (p == n + 1 || a[p] == 0) {
                dir = 0;
                continue;
            }
            if (p == 1) {
                if (!a[p]) {
                    break;
                }
                --a[p];
                ans += 'R';
                ++p;
                continue;
            }
            if (a[p] == 1 && a[p - 1] > 1) {
                dir = 0;
                continue;
            }
            --a[p];
            ans += 'R';
            ++p;
            continue;
        } else {
            if (p == 1 || a[p - 1] == 0) {
                dir = 1;
                continue;
            }
            if (p == n + 1) {
                if (!a[p - 1]) {
                    break;
                }
                --a[p - 1];
                ans += 'L';
                --p;
                continue;
            }
            if (a[p - 1] == 1 && a[p] > 1) {
                dir = 1;
                continue;
            }
            --a[p - 1];
            ans += 'L';
            --p;
            continue;
        }
        break;
    }
    cout << ans << endl;
    return 0;
}