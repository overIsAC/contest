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

pair<int, vector<LL>> f() {
    int sign = 1;
    int n;
    cin >> n;
    vector<LL> a(1e5 + 1, 0);
    while (n--) {
        int op, x;
        cin >> op >> x;
        if (x < 0) {
            x = -x;
            sign = -sign;
        }
        if (op == 1) {
            ++a[x];
        } else {
            --a[x];
        }
    }
    for (int i = 2; i <= 1e5; ++i) {
        for (int j = i + i; j <= 1e5; j += i) {
            if (!a[j]) {
                continue;
            }
            int k = j;
            while (k % i == 0) {
                a[i] += a[j];
                k /= i;
            }
            a[k] += a[j];
            a[j] = 0;
        }
    }

    a[1] = 0;

    return {sign, a};
}

int main() {
    auto a = f();
    auto b = f();

    if (a == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}