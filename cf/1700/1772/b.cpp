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

int a[22][22];

void rot() {
    int t = a[0][0];
    a[0][0] = a[1][0];
    a[1][0] = a[1][1];
    a[1][1] = a[0][1];
    a[0][1] = t;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
        bool ok =false;
        for (int i = 0; i < 5; ++i) {
            if (a[0][0] < a[0][1] && a[1][0] < a[1][1] && a[0][0] < a[1][0] && a[0][1] < a[1][1]) {
                ok = true;
            }
            rot();
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}