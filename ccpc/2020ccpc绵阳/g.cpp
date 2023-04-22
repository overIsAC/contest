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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, Case = 0;
    cin >> T;
    while (T--) {
        cout << "Case #" << ++Case << ": ";
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (!((LL)b + c + d)) {
            if (a == 0) {
                cout << "Horse" << endl;
                continue;
            }
            if (a & 1) {
                cout << "Horse" << endl;
            } else {
                cout << "Rabbit" << endl;
            }
            continue;
        }
        int win = 0;
        if (b % 3 == 0) {
            if (c < b / 3) {
                int L = c, R = b / 3;
                if ((R - L) + 1 >> 1 & 1) {
                    win = 1;
                }
            }
        } else if (b % 3 == 1) {
            if (c <= b / 3) {
                int L = c + 1, R = b / 3 + 1;
                if ((R - L + 1) + 1 >> 1 & 1) {
                } else {
                    win = 1;
                }
            } else {
                win = 1;
            }
        } else {
            b -= 2;
            if (c < b / 3) {
                int L = c, R = b / 3;
                if ((R - L) + 1 >> 1 & 1) {
                    win = 1;
                }
            }
            win ^= 1;
        }
        if (a % 2 == 1) {
            win ^= 1;
        }
        if (win) {
            cout << "Rabbit" << endl;
        } else {
            cout << "Horse" << endl;
        }
    }
    return 0;
}