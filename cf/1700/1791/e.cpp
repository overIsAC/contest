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
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }
        LL sum = 0;
        int minv = 1e9;
        int cnt = 0;
        for (auto &i : a) {
            sum += abs(i);
            minv = min(minv, abs(i));
            if (i < 0) {
                ++cnt;
            }
        }
        if (cnt % 2 == 0) {
            cout << sum << endl;
        } else {
            cout << sum - 2 * minv << endl;
        }
    }
    return 0;
}