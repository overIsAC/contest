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
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);
    while (y % (m * d)) {
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
            month[2] = 29;
        } else {
            month[2] = 28;
        }
        ++d;
        if (month[m] < d) {
            d = 1;
            ++m;
        }
        if (m > 12) {
            ++y;
            m = 1;
        }
    }
    printf("%04d/%02d/%02d\n", y, m, d);
    return 0;
}