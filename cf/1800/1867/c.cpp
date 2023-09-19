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
    function
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        set<int> s;
        for (int i = 1; i <= n; ++i) {
            int a;
            cin >> a;
            s.insert(a);
        }
        int mex = 0;
        while (s.count(mex)) {
            ++mex;
        }
        cout << mex << endl;
        int y;
        cin >> y;
        while (y != -1) {
            cout << y << endl;
            cin >> y;
        }
    }
    return 0;
}