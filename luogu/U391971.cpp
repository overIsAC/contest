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

LL g(vector<int> a) {
    sort(a.begin(), a.end());
    if (a[0] != a[2]) {
        if (a[2] - a[0] < a[0]) {
            return 1 + g({a[0], a[1], a[2] - a[0]});
        }
        return a[2] / a[0] - 1 + g({a[0], a[1], a[2] % a[0] + a[0]});
    } else {
        return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << g({a, b, c}) << endl;
    }
    return 0;
}