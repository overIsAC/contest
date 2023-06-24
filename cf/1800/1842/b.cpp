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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n), b(n), c(n);
        for (auto &i : a) {
            cin >> i;
        }
        for (auto &i : b) {
            cin >> i;
        }
        for (auto &i : c) {
            cin >> i;
        }
        int d = 0;
        for (auto &i : a) {
            if ((i | x) > x) {
                break;
            }
            d |= i;
        }
        for (auto &i : b) {
            if ((i | x) > x) {
                break;
            }
            d |= i;
        }
        for (auto &i : c) {
            if ((i | x) > x) {
                break;
            }
            d |= i;
        }
        if (d == x) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}