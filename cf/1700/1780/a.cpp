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

int a[N], n;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> z[2];
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            z[a[i] & 1].push_back(i);
        }
        if (z[1].size() >= 3) {
            cout << "YES" << endl;
            for (int i = 0; i < 3; ++i) {
                cout << z[1][i] << ' ';
            }
            cout << endl;
        } else if (z[1].size() >= 1 && z[0].size() >= 2) {
            cout << "YES" << endl;
            cout << z[1][0] << " " << z[0][0] << ' ' << z[0][1] << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}