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

int query(int a, int b, int c, int d) {
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    char z;
    cin >> z;
    return z;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a = 0, b = 1;
        for (int i = 2; i < n; ++i) {
            int c = i;
            int r = query(a, b, b, c);
            if (r == '<') {
                swap(a, c);
            }
            r = query(b, a, a, c);
            if (r == '<') {
                swap(b, c);
            }
        }
        cout << "! " << a << ' ' << b << endl;
    }
    return 0;
}