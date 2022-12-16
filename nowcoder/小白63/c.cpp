#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N], b[N];
int c[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        c[i] = i;
    }
    int u = 0, v = 0, w = 0;
    do {
        int x = 0, y = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > b[c[i]]) {
                ++x;
            } else if (a[i] < b[c[i]]) {
                ++y;
            }
        }
        if (x == y) {
            ++w;
        } else if (x > y) {
            ++u;
        } else {
            ++v;
        }
    } while (next_permutation(c + 1, c + n + 1));
    cout << u << ' ' << v << ' ' << w << endl;
    return 0;
}