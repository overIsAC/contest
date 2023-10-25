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
const int N = 3 + 1e5;

int y, m, d, w;
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n;
int ans[10];

int isLeap(int y) {
    return y % 400 == 0 || y % 100 != 0 && y % 4 == 0;
}

int main() {
    cin >> n;
    y = 1900;
    m = 1;
    d = 1;
    w = 1;

    while (y != 1900 + n) {
        if (d == 13) {
            ++ans[w];
        }

        w = (w + 1) % 7;
        if (isLeap(y)) {
            month[2] = 29;
        } else {
            month[2] = 28;
        }
        ++d;
        if (d > month[m]) {
            d = 1;
            ++m;
        }
        if (m > 12) {
            m = 1;
            ++y;
        }
    }
    for (int i = 6;;) {
        cout << ans[i] << ' ';
        i = (i + 1) % 7;
        if (i == 6) {
            break;
        }
    }
    return 0;
}